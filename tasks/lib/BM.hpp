#pragma once

#include "MT.hpp"
class BM {
 private:
  unsigned long int seed;
  MT generator;

 public:
  BM(unsigned long int seed);
  ~BM(void);
  void genrand_real1(double *x1, double *x2);
};