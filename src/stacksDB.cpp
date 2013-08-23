/*
 * =====================================================================================
 *
 *       Filename:  stacksDB.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  13-08-23 08:43:19 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ryan F. McCormick (), ryanabashbash@tamu.edu
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <iostream>
#include <mysql++.h>
#include "stacksDB.h"
#include "SNP.h"


int getWhitelist (const char *pcc_db, const char *pcc_server,
	       const char *pcc_user, const char *pcc_password)
{
	mysqlpp::String greeting("Hello from getWhitelist");
	std::cout << greeting << std::endl;

	// Connect to the sample database.
	mysqlpp::Connection conn(false);
	if (conn.connect(pcc_db, pcc_server, pcc_user, pcc_password)) {
		
		// Retrieve high quality tags
		mysqlpp::Query query = conn.query("SELECT tag_id \
				FROM catalog_index \
				WHERE progeny>=200 \
				LIMIT 5");
		//Store the tags
		std::vector<int> vi_tags;
		std::vector<std::string> vstr_tags;
		if (mysqlpp::StoreQueryResult res = query.store()) {
			for (size_t i = 0; i < res.num_rows(); ++i) {
				//Conver mysqlpp::String to std::string before pushing back
				std::string test_str = std::string(res[i]["tag_id"].data(), res[i]["tag_id"].length());
				vstr_tags.push_back(test_str);
				//Push back the return
				vi_tags.push_back(res[i]["tag_id"]);
				std::cout << res[i]["tag_id"] << std::endl;
			}
			std::cout << "Number of rows returned " << res.num_rows() << std::endl;
			
			for (size_t i = 0; i < vi_tags.size(); ++i) {
				std::cout << vi_tags[i] << std::endl;
			}	
			for (size_t i = 0; i < vstr_tags.size(); ++i) {
				std::cout << vstr_tags[i] << std::endl;
			}
			
			/*std::cout << "We have:" << std::endl;
			//For each item in the result
            		mysqlpp::StoreQueryResult::const_iterator it;
            		for (it = res.begin(); it != res.end(); ++it) {
                	mysqlpp::Row row = *it;
			std::cout << "\t Row: " << row[0] << " " << row.field_list() << std::endl;
            		}*/
        	}
        	else {
			std::cerr << "Failed to get item list: " << query.error() << std::endl;
            		return 1;
        	}

        	return 0;
    	}
    	else {
		std::cerr << "DB connection failed: " << conn.error() << std::endl;
        	return 1;
    	}
	return EXIT_SUCCESS;
}


int getAllelesAndCoordinates(const char *pcc_db, const char *pcc_server,
	       const char *pcc_user, const char *pcc_password, 
	       std::vector<int> vi_tags)
{
	std::cout << "Hello from getAllelesAndCoordinates" << std::endl;
	for(size_t i=0; i<vi_tags.size(); ++i) {
		std::cout << vi_tags[i] << std::endl;
	}
	//Test the SNP class
	SNP snp1;
	snp1.setCoordinate(200);
	snp1.getCoordinate();
	// Connect to the sample database.
	mysqlpp::Connection conn(false);
	if (conn.connect(pcc_db, pcc_server, pcc_user, pcc_password)) {
		
		// Retrieve high quality tags
		mysqlpp::Query query = conn.query("SELECT tag_id, allele FROM catalog_alleles WHERE tag_id=%0:tagID LIMIT 5");
		query.parse();
		//Store the tags
		std::vector<const char*> vc_tags;
		std::vector<std::string> vstr_tags;
		if (mysqlpp::StoreQueryResult res = query.store("7352")) {
			for (size_t i = 0; i < res.num_rows(); ++i) {
				//Conver mysqlpp::String to std::string before pushing back
				std::string test_str = std::string(res[i]["allele"].data(), res[i]["allele"].length());
				vstr_tags.push_back(test_str);
				//Push back the return
				vc_tags.push_back(res[i]["allele"]);
				std::cout << res[i]["allele"] << std::endl;
			}
			std::cout << "Number of rows returned " << res.num_rows() << std::endl;
			
			for (size_t i = 0; i < vc_tags.size(); ++i) {
				std::cout << vc_tags[i] << std::endl;
			}	
			for (size_t i = 0; i < vstr_tags.size(); ++i) {
				std::cout << vstr_tags[i] << std::endl;
			}
			
			/*std::cout << "We have:" << std::endl;
			//For each item in the result
            		mysqlpp::StoreQueryResult::const_iterator it;
            		for (it = res.begin(); it != res.end(); ++it) {
                	mysqlpp::Row row = *it;
			std::cout << "\t Row: " << row[0] << " " << row.field_list() << std::endl;
            		}*/
        	}
        	else {
			std::cerr << "Failed to get item list: " << query.error() << std::endl;
            		return 1;
        	}

        	return 0;
    	}
    	else {
		std::cerr << "DB connection failed: " << conn.error() << std::endl;
        	return 1;
    	}

	return EXIT_SUCCESS;
}
