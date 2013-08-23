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

void SNP::getCoordinate()
{
	std::cout << "SNP coordinate: " << coordinate << std::endl;
}

void SNP::setCoordinate(int coord)
{
	coordinate = coord;
}
