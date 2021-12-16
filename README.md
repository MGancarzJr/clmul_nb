# clmul_nb
Branchless CLMUL library.

The purpose of this library is to provide a low-level, branchless CLMUL (carry-less multiplication) implementation for architecture which does not support hardware acceleration of cryptographic operations. It is intended as a teaching aid and should be carefully tested before use in production code.

Branchless programming was chosen to mitigate potential timing side-channel attacks. Both the polynomial expansion and reduction steps occur whether the target bit(s) are high or low. This is accomplished by multiplying the shifted polynomial and the modulo by the target bit either retaining the original value or zeroing-out the polynomial and/or the modulo. The storage variable is then XORed by this value either obtaining a new value in the case that the target bit was 1 or no change in the other case. This avoids conditional branches and potentially different power draw and/or execution time differences.

A full definition of this algorithm can be obtained in the [NIST FIPS 197 Advanced Encryption Standard (AES)](https://nvlpubs.nist.gov/nistpubs/fips/nist.fips.197.pdf) § 4.3 Polynomials with Coefficients in GF(2^8).