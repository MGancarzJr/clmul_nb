//////////////////////////////////////////////////////////////////////////////
// File: clmul_nb.h
// Author: Maciej Gancarz Jr
// Date: December 16, 2021 
// Version: 1.0
// License: GNU General Public License v3.0
//
// clmul_nb accepts two unsigned integers and performs a carry-less multi-
// plication operation on the lowest bytes. This operation is defined in NIST
// FIPS 197 Advanced Encryption Standard (AES) § 4.3 which is available at the
// url: https://nvlpubs.nist.gov/nistpubs/fips/nist.fips.197.pdf
//
// The purpose of this library is to provide a low-level algorithm for chip
// architectures which do not support cryptographic acceleration. The algo-
// rithm is designed to avoid branching conditions in the expansion and re-
// duction phases of the polynomial multiplication.
//////////////////////////////////////////////////////////////////////////////

#ifndef CLMUL_NB_H_
#define CLMUL_NB_H_

#ifdef __cplusplus
extern "C" {
#endif

    unsigned int clmul_nb(unsigned int first_polynomial, unsigned int second_polynomial);

#ifdef __cplusplus
}
#endif

#endif