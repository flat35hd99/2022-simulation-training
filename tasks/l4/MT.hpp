#pragma once

/* Period parameters */
#define MT_N 624
#define MT_M 397
#define MATRIX_A 0x9908b0dfUL   /* constant vector a */
#define UPPER_MASK 0x80000000UL /* most significant w-r bits */
#define LOWER_MASK 0x7fffffffUL /* least significant r bits */

class MT {
 private:
  unsigned long int mt[MT_N];
  int mti = MT_N + 1;

 public:
  MT();
  MT(unsigned long int s);
  unsigned long int genrand_int32(void);
  double genrand_real1(void);
};