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

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description: main function 
 * =====================================================================================
 */
int main ( int argc, char *argv[] )
{
	testcon("Hegari", "localhost", "stacks", "");
	std::cout << "Hello from main" << std::endl;
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
