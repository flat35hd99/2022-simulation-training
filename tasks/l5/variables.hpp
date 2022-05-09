#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class Variables {
 public:
  std::vector<double> r_x;
  std::vector<double> r_y;
  double L = 40;
  Variables(){

  };
  ~Variables(){};
  void add_atom(double x, double y) {
    r_x.push_back(x);
    r_y.push_back(y);
  }
  void write_coordinates(std::string filename) {
    std::ofstream outputfile(filename);
    for (int i = 0; i < r_x.size(); i++) {
      outputfile << r_x[i] << " " << r_y[i] << "\n";
    }
    outputfile.close();
  }
};
