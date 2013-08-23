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
#include "cmdline.h"
#include "printdata.h"
#include <mysql++.h>
#include "stacksDB.h"


int testcon (const char *pcc_db, const char *pcc_server,
	       const char *pcc_user, const char *pcc_password)
{
	mysqlpp::String greeting("Hello from mysqlpp");
	std::cout << greeting << std::endl;	
	// Connect to the sample database.
	mysqlpp::Connection conn(false);
	std::cout << "Attempting to connect at server " << pcc_server << "with user " << pcc_user << std::endl;
	if (conn.connect(pcc_db, pcc_server, pcc_user, pcc_password)) {
		// Retrieve a subset of the sample stock table set up by resetdb
		// and display it.
		mysqlpp::Query query = conn.query("select item from stock");
		if (mysqlpp::StoreQueryResult res = query.store()) {
			std::cout << "We have:" << std::endl;
            		mysqlpp::StoreQueryResult::const_iterator it;
            		for (it = res.begin(); it != res.end(); ++it) {
                	mysqlpp::Row row = *it;
			std::cout << '\t' << row[0] << std::endl;
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

