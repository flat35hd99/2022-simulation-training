#include <math.h>

#include <string>

#include "variables.hpp"

int main() {
  Variables variables;
  double x, y;
  double dl = variables.L / sqrt(256);
  for (int i = 0; i < static_cast<int>(sqrt(256)); i++) {
    for (int j = 0; j < static_cast<int>(sqrt(256)); j++) {
      x = i * dl;
      y = j * dl;
      variables.add_atom(x, y);
    }
  }
  std::string filename("hoge.txt");
  variables.write_coordinates(filename);
  return 0;
}
