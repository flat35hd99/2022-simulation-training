#include <stdio.h>

#include "../lib/BM.hpp"
using namespace std;
int main(void) {
  BM hoge(1);
  int N = 1e5;
  double results[2 * N];
  double x1, x2;
  for (int i = 0; i < N; i++) {
    hoge.genrand_real1(&x1, &x2);
    /* results is array, not list.
    When you perform "=" operation, array get real value instead of pointer of
    the variables.
    */
    results[2 * i] = x1;
    results[2 * i + 1] = x2;
  }

  for (int i = 0; i < N; i++) {
    printf("%.20f\n%.20f\n", results[i * 2], results[i * 2 + 1]);
  }

  return 0;
}