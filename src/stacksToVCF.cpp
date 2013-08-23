/*
 * =====================================================================================
 *
 *       Filename:  stacksToVCF.cpp
 *
 *    Description:  Interacts with a Stacks database to generate VCF output
 *
 *        Version:  1.0
 *        Created:  13-08-23 08:29:22 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ryan F. McCormick (), ryanabashbash@tamu.edu
 *   Organization:  Texas A&M University
 *
 * =====================================================================================
 */
#include	<stdlib.h>
#include	<iostream>
#include	"stacksDB.h"
#include	"SNP.h"

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description: main function 
 * =====================================================================================
 */
int main ( int argc, char *argv[] )
{
	std::cout << "Hello from main" << std::endl;
	getWhitelist("HegariX80M_051313_radtags", "localhost", "stacks", "");
	//This vector is for testing
	static const int arr [] = {7352,7755,10837,12641,16596};
	std::vector<int> vi_tags (arr, arr + sizeof(arr) / sizeof(arr[0]) );
	getAllelesAndCoordinates("HegariX80M_051313_radtags", "localhost", "stacks", "", vi_tags);	
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
