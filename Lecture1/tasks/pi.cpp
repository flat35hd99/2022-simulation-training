#include <math.h>    // for sin(),cos(), etc
#include <stdio.h>   // for printf, etc
#include <stdlib.h>  // for rand(), etc
#include <time.h>    // for time(NULL), etc

#include <fstream>  // for ifstream/ofstream
#include <iomanip>
#include <iostream>  // for cout, etc
using namespace std;
int main(void) {
  int i, count, max = 1e+9, observe_span = 1e+4;
  double x, y, z, pi;

  srand(1234);

  for (i = 0; i < max; i++) {
    x = (double)rand() / RAND_MAX;
    y = (double)rand() / RAND_MAX;
    z = x * x + y * y;
    if (z < 1) {
      count++;
    }
    if ((i + 1) % observe_span == 0) {
      pi = (double)count / (i + 1) * 4;
      printf("%d,%.20f\n", i + 1, pi);
    }
  }
  return 0;
}
