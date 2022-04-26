#include <stdio.h>
#include <stdlib.h>

#include "../lib/BM.hpp"
using namespace std;
int main(void) {
  BM bm(1);
  int N = 1e7;
  double x1, x2;
  for (int i = 0; i < N; i++) {
    bm.genrand_real1(&x1, &x2);
    printf("%.20f\n%.20f\n", x1, x2);
  }

  return 0;
}