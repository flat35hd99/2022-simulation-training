#include <math.h>    // for sin(),cos(), etc
#include <stdio.h>   // for printf, etc
#include <stdlib.h>  // for rand(), etc
#include <time.h>    // for time(NULL), etc

#include <fstream>  // for ifstream/ofstream
#include <iomanip>  // for setprecision()
#include <iomanip>
#include <iostream>  // for cout, etc
using namespace std;
int main(void) {
  int i, count = 0, max = 1e+5;
  double x, y, z, pi;
  char fname[128];
  ofstream file;
  srand(time(NULL));
  sprintf(fname, "coord%d.dat", max);
  file.open(fname);
  for (i = 0; i < max; i++) {
    x = (double)rand() / RAND_MAX;
    y = (double)rand() / RAND_MAX;
    z = x * x + y * y;
    if (z < 1) {
      count++;
      file << x << " " << y << endl;
    }
  }
  pi = (double)count / max * 4;
  printf("%.20f\n", pi);  // by C, %.20f -- Displaying with 20 decimal precision
  cout << std::setprecision(21) << pi << endl;  // by C++
  // std::cout << std::setprecision(21)  <<  pi  << endl; // without "using
  // namespace std;"
  return 0;
}
