#include <stdio.h>
#include <stdlib.h>

#include <limits>

int main(int argc, char const *argv[]) {
  double v, dt, range;
  int i, steps, observe_span;
  v = 10;
  dt = atof(argv[1]);
  range = 1e4;
  steps = (int)range / dt;

  constexpr double epsilon = std::numeric_limits<double>::epsilon();

  for (int i = 0; i < steps; i++) {
    v = (1 - dt) * v;
    printf("%.20f\n", v);
    if (v <= epsilon) {
      break;
    }
  }
  return 0;
}
