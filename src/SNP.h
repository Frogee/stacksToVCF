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
		void getCoordinate();
		void setCoordinate(int coord);
	private:
		int coordinate;
};
#endif   /* ----- #ifndef SNP_H_INC  ----- */
