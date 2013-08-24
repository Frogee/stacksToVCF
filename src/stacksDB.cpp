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
	//Initialize the vector of SNPs
	std::vector<SNP> vSNP_snps;
	// Connect to the sample database.
	mysqlpp::Connection conn(false);
	if (conn.connect(pcc_db, pcc_server, pcc_user, pcc_password)) {
		
		// Retrieve alleles
		mysqlpp::Query query = conn.query("SELECT tag_id, rank_1, rank_2, col \
				FROM catalog_snps \
				WHERE tag_id=%0:tagID \
				LIMIT 5");
		query.parse();
		SNP snp;
		if (mysqlpp::StoreQueryResult res = query.store("180")) {
			std::cout << "Query successful; parsing" << std::endl;
			//For each row in the query result
			for (size_t i = 0; i < res.num_rows(); ++i) {
				snp.setTag(res[i]["tag_id"]);
				snp.setOffset(res[i]["col"]);
				snp.setTmpAllele1(res[i]["rank_1"]);
				snp.setTmpAllele2(res[i]["rank_2"]);
				snp.printSNP();
				//Set up a query to get bp and strandedness
				//Would using a join be faster here?
				mysqlpp::Query subquery = conn.query("SELECT tag_id, chr, bp, strand \
						FROM catalog_tags \
						WHERE tag_id=%0:tagID \
						LIMIT 1");
				subquery.parse();
				if (mysqlpp::StoreQueryResult subres = subquery.store("180")) {
					std::cout << "Subquery successful; parsing" << std::endl;
					//For each row in the query result
					for (size_t j=0; j < subres.num_rows(); ++j) {
						snp.setChr(subres[j]["chr"]);
						snp.setTagCoordinates(subres[j]["bp"]);
						snp.setStrand(subres[j]["strand"]);
					}
				} // End subquery

				vSNP_snps.push_back(snp);
			}
			std::cout << "Number of rows returned " << res.num_rows() << std::endl;
			
			for (size_t i = 0; i < vSNP_snps.size(); ++i) {
				vSNP_snps[i].printSNP();
			}	
			//return vSNP_snps;	
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
