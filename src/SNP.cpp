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
#include <string>
#include <mysql++.h>
#include "SNP.h"

//Constructors
SNP::SNP()
{
	coordinate = tag_coordinate = tag = 0;
	ref_allele = alt_allele = tmp_allele1 = tmp_allele2 = "N";
	chr = "chromosome_n";
	strand = "null";
}
//General functions
void SNP::printSNP()
{
	std::cout << "SNP info:" << std::endl <<
		"\t" << "Tag ID: " << tag << std::endl <<
		"\t" << "Chromosome: " << chr << std::endl <<
		"\t" << "Coordinate: " << coordinate << std::endl <<
		"\t" << "Tag coordinate: " << tag_coordinate << std::endl <<
		"\t" << "Strand: " << strand << std::endl <<
		"\t" << "Offset: " << offset << std::endl <<
		"\t" << "Reference allele: " << ref_allele << std::endl <<
		"\t" << "Alt allele: " << alt_allele << std::endl <<
		"\t" << "Tmp allele1: " << tmp_allele1 << std::endl <<
		"\t" << "Tmp allele2: " << tmp_allele2 << std::endl;
}

//Tag functions
void SNP::setTag(int tagID)
{
	tag = tagID;
}
//Chromosome functions
void SNP::setChr(mysqlpp::String chromosome)
{
	chr = std::string(chromosome.data(), chromosome.length());
}

void SNP::setStrand(mysqlpp::String strandtype)
{
	strand = std::string(strandtype.data(), strandtype.length());
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

void SNP::setTagCoordinates(int coord)
{
	tag_coordinate = coord;
}

void SNP::printOffset()
{
	std::cout << "SNP offest: " << offset << std::endl;
}

void SNP::setOffset(int col)
{
	offset = col;
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
