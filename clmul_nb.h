/* File clmul_nb.h */
#ifndef CLMUL_NB_H_
#define CLMUL_NB_H_

/* Carry-less multiplication of two bytles.
*
*
* clmul_nb takes two unsigned integers and returns an unsigned integer. Only the lowest 8 bits of each integers will be considered. This operation is defined in NIST FIPS 197 §4.2 (https://nvlpubs.nist.gov/nistpubs/fips/nist.fips.197.pdf).
*/
unsigned int clmul_nb(unsigned int first_polynomial, unsigned int second_polynomial);

#endif