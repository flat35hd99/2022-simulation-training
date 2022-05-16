#pragma once

#include <vector>

#include "variables.hpp"

class MD {
 public:
  Variables variables;
  MD() {
    Variables variables;
    std::vector<std::vector<int>> verlet_list(variables.N,
                                              std::vector<int>(variables.N));
  };
  ~MD(){};
  void compute_force() {
    double distance;
    for (int i = 0; i < variables.N; i++) {
      for (int j = i + 1; j < variables.N; j++) {
        distance = variables.r_x[i] - variables.r_y[j];
        if (distance > variables.L) {
          distance -= variables.L;
        }
        if (distance < variables.verlet_cutoff) {
          verlet_list[i].push_back(j);
        }
      }
    }
  }

 private:
  std::vector<std::vector<int>> verlet_list;
};