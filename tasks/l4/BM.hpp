#pragma once

#include "MT.hpp"
class BM {
 private:
  unsigned long int seed;
  MT generator;

 public:
  BM(unsigned long int seed) { MT generator(seed); };
  ~BM(void){};
  void genrand_real1(double *x1, double *x2) {
    double u1 = generator.genrand_real1();
    double u2 = generator.genrand_real1();
    *x1 = sqrt(-2 * log(u1)) * cos(2 * M_PI * u2);
    *x2 = sqrt(-2 * log(u2)) * cos(2 * M_PI * u1);
  };
};