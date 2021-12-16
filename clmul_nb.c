//////////////////////////////////////////////////////////////////////////////
// File: clmul_nb.c
// Author: Maciej Gancarz Jr
// Date: December 16, 2021 
// Version: 1.0
// License: GNU General Public License v3.0
//////////////////////////////////////////////////////////////////////////////

#include "clmul_nb.h"

unsigned int clmul_nb(unsigned int first_polynomial, unsigned int second_polynomial) {
    // Sanitize the inputs.
    first_polynomial &= 0xff;
    second_polynomial &= 0xff;

    unsigned int accumulator = 0x0;
    const unsigned int modulo = 0x011b;

    // Shift the second and first polinomials.
    // Check the lowest bit on the first polinomial. Multiply the second polynomial by this bit.
    // Store resulting value (shifted second polynomial or 0) in accumulator via XOR.
    // Repeat for bits 0 through 6 of first polynomial.
    for(int i = 0; i < 8; i++) {
        accumulator ^= ((second_polynomial << i) * ((first_polynomial >> i ) & 0x1));
    }

    // Shift the modulo.
    // Check the highest possible bit on the accumulator.
    // Multiply the modulo by this bit.
    // XOR the accumulator by the shifted modulo or 0.
    // Repeat for bits 13 through 8 of accumulator.
    for(int i = 0; i < 7; i++) {
        accumulator ^= ((modulo << (6 - i)) * ((accumulator >> (14 - i)) & 0x1));
    }

    return accumulator;
}