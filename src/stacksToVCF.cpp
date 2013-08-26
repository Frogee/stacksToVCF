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
#include	"biopRefAllele.h"

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description: main function 
 * =====================================================================================
 */
int main ( int argc, char *argv[] )
{
	std::cerr << "Running main" << std::endl;

	//Generate a whitelist of tags from the database whose SNPs will be output to the VCF
	std::vector<int> vi_whitelist = getWhitelist("HegariX80M_051313_radtags", "localhost", "stacks", "");

	//This vector is for testing 
	//static const int arr [] = {55,111,179,384,385,1256,1260};
	//std::vector<int> vi_tags (arr, arr + sizeof(arr) / sizeof(arr[0]) );
	//End test vector
	
	//Get the relevant SNP information from the whitelisted tags
	std::vector<SNP> vSNP_snps = getAllelesAndCoordinates("HegariX80M_051313_radtags", "localhost", "stacks", "", vi_whitelist);
	
	/*for (size_t i = 0; i < vSNP_snps.size(); ++i) {
		vSNP_snps[i].printSNP();
	}*/

	//Identify the reference allele for each SNP by system calls to biopieces
	vSNP_snps = getRefAllele(vSNP_snps);

	/*for (size_t i = 0; i < vSNP_snps.size(); ++i) {
		vSNP_snps[i].printSNP();
	}*/

	//Output in VCF format
	std::cout << "##fileformat=VCFv4.1" << std::endl <<
		"##fileDate=20132608" << std::endl <<
		"##source=StacksDB" << std::endl <<
		"##INFO=<ID=DB,Number=1,Type=String,Description=\"Database of origin\"" << std::endl <<
		"##FILTER=<ID=80prg,Description=\"Found in less than 80\% of progeny\"" << std::endl <<
		"##FORMAT=<ID=PH,Number=1,Description=\"Placeholder\"" << std::endl <<
		"#CHROM\tPOS\tID\tREF\tALT\tQUAL\tFILTER\tINFO\tFORMAT" << std::endl;
	for (size_t i = 0; i < vSNP_snps.size(); ++i) {
		std::cout << vSNP_snps[i].getChr() << "\t" << vSNP_snps[i].getCoord() << "\t" <<
			vSNP_snps[i].getChr() << "_" << vSNP_snps[i].getCoord() << "_" << vSNP_snps[i].getTag() << "\t" <<
			vSNP_snps[i].getRefAllele() << "\t" << vSNP_snps[i].getAltAllele() << "\t" <<
		       "0" << "\t" << "PASS" << "\t" << "DB=Test" << "\t" << "PH" << std::endl;	
	}

	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
