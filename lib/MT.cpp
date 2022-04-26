#include "MT.hpp"

/* initializes mt[MT_N] with a seed */
MT::MT(unsigned long s) {
  mt[0] = s & 0xffffffffUL;
  for (mti = 1; mti < MT_N; mti++) {
    mt[mti] = (1812433253UL * (mt[mti - 1] ^ (mt[mti - 1] >> 30)) + mti);
    /* See Knuth TAOCP Vol2. 3rd Ed. P.106 for multiplier. */
    /* In the previous versions, MSBs of the seed affect   */
    /* only MSBs of the array mt[].                        */
    /* 2002/01/09 modified by Makoto Matsumoto             */
    mt[mti] &= 0xffffffffUL;
    /* for >32 bit machines */
  }
}

/* generates a random number on [0,0xffffffff]-interval */
unsigned long MT::genrand_int32(void) {
  unsigned long y;
  static unsigned long mag01[2] = {0x0UL, MATRIX_A};
  /* mag01[x] = x * MATRIX_A  for x=0,1 */

  if (mti >= MT_N) { /* generate N words at one time */
    int kk;

    for (kk = 0; kk < MT_N - MT_M; kk++) {
      y = (mt[kk] & UPPER_MASK) | (mt[kk + 1] & LOWER_MASK);
      mt[kk] = mt[kk + MT_M] ^ (y >> 1) ^ mag01[y & 0x1UL];
    }
    for (; kk < MT_N - 1; kk++) {
      y = (mt[kk] & UPPER_MASK) | (mt[kk + 1] & LOWER_MASK);
      mt[kk] = mt[kk + (MT_M - MT_N)] ^ (y >> 1) ^ mag01[y & 0x1UL];
    }
    y = (mt[MT_N - 1] & UPPER_MASK) | (mt[0] & LOWER_MASK);
    mt[MT_N - 1] = mt[MT_M - 1] ^ (y >> 1) ^ mag01[y & 0x1UL];

    mti = 0;
  }

  y = mt[mti++];

  /* Tempering */
  y ^= (y >> 11);
  y ^= (y << 7) & 0x9d2c5680UL;
  y ^= (y << 15) & 0xefc60000UL;
  y ^= (y >> 18);

  return y;
}

double MT::genrand_real1(void) {
  return genrand_int32() * (1.0 / 4294967295.0);
  /* divided by 2^32-1 */
}