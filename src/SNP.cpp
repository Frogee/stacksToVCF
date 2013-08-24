/*
 * =====================================================================================
 *
 *       Filename:  SNP.cpp
 *
 *    Description:  Contains the SNP class
 *
 *        Version:  1.0
 *        Created:  13-08-23 05:12:19 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ryan F. McCormick (), ryanabashbash@tamu.edu
 *   Organization:  Texas A&M University  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <iostream>
#include "SNP.h"

//Constructors
SNP::SNP()
{
	coordinate=0;
	ref_allele = alt_allele = tmp_allele1 = tmp_allele2 = "N";
}
//Coordinate functions
void SNP::printCoordinates()
{
	std::cout << "SNP coordinate: " << coordinate << std::endl;
}

void SNP::setCoordinates(int coord)
{
	coordinate = coord;
}

//Allele functions
void SNP::printAlleles()
{
	std::cout << "Reference allele: " << ref_allele << std::endl <<
		"Alternate allele: " << alt_allele << std::endl <<
		"tmp allele 1: " << tmp_allele1 << std::endl <<
		"tmp allele 2: " << tmp_allele2 << std::endl;
}
void SNP::setRefAllele(const char *allele)
{
	ref_allele = allele;
}

void SNP::setAltAllele(const char *allele)
{
	alt_allele = allele;
}

void SNP::setTmpAllele1(const char *allele)
{
	tmp_allele1 = allele;
}

void SNP::setTmpAllele2(const char *allele)
{
	tmp_allele2 = allele;
}
