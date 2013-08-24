/*
 * =====================================================================================
 *
 *       Filename:  SNP.h
 *
 *    Description:  Header file for the SNP class
 *
 *        Version:  1.0
 *        Created:  13-08-23 05:14:59 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ryan F. McCormick (), ryanabashbash@tamu.edu
 *   Organization:  
 *
 * =====================================================================================
 */


#ifndef  SNP_H_INC
#define  SNP_H_INC

class SNP {
	public:
		//Constructors
		SNP();
		//Destructors
		//~SNP();
		//Members for coordinates
		void printCoordinates();
		void setCoordinates(int coord);
		//Members for alleles
		void printAlleles();
		void setRefAllele(const char *allele);   
		void setAltAllele(const char *allele);
		void setTmpAllele1(const char *allele);
		void setTmpAllele2(const char *allele);
	private:
		int coordinate;
		const char *ref_allele;
	 	const char *alt_allele;
		const char *tmp_allele1;
		const char *tmp_allele2;
};
#endif   /* ----- #ifndef SNP_H_INC  ----- */
