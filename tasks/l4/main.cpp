#include <math.h>

#include <array>

#include "BM.hpp"

constexpr int N = 3e5;

/*Compute velocity using semi-implicit Maruyama-Euler method

*/
std::array<double, N> md(double v0, double r0, double T, double dt) {
  std::array<double, N> v_recorder = {};

  // initialize
  double r = r0;
  double v = v0;
  BM generator = BM(1);

  // Pre-computation of constant value
  const double prefactor_v = 1 - dt;
  const double prefactor_R = sqrt(2 * T * dt);

  // Random values
  double u1, u2;

  for (int i = 0; i < N / 2; i++) {
    // Once you generate two random numbers,
    // you can forward 2 dt.
    generator.genrand_real1(&u1, &u2);

    v = prefactor_v * v + prefactor_R * u1;
    r = r + v * dt;
    v_recorder[i] = v;

    v = prefactor_v * v + prefactor_R * u2;
    r = r + v * dt;
    v_recorder[i + 1] = v;
  }
  return v_recorder;
}

double squared_mean(std::array<double, N> samples) {
  double squared_sum = 0;
  const int n_samples = samples.size();
  for (int i = 0; i < n_samples; i++) {
    squared_sum += samples[i] * samples[i];
  }
  return squared_sum / static_cast<double>(n_samples);
}

double diffusion_coefficient(std::array<double, N> samples, int dimensions,
                             double dt) {
  const int n_samples = samples.size();
  // pre difine to use omp declaration
  double diffusion = 0;
  double acf;
  int i, d_step;
#pragma omp parallel for private(d_step, acf, i) reduction(+ : diffusion)
  for (d_step = 0; d_step < n_samples; d_step++) {
    // auto correlation function of each delta of step
    acf = 0;
    for (i = 0; i < n_samples - d_step; i++) {
      acf += samples[i] * samples[i + d_step];
    }
    diffusion += acf * dt / static_cast<double>(n_samples - d_step);
  }
  return diffusion / static_cast<double>(dimensions);
}

int main() {
  double a = 1;
  double t_0 = 1;
  double dt = 0.001;
  for (int i = 0; i < 8; i++) {
    // Configuration
    double T = 0.5 * static_cast<double>(i);
    // Run MD
    std::array<double, N> v = md(a, t_0, T, dt);
    // Compute statistical quantities
    double sm = squared_mean(v);
    double D = diffusion_coefficient(v, 1, dt);
    printf("T = %03f: r^2 = %03f, D = %e\n", T, sm, D);
  }

  return 0;
}
