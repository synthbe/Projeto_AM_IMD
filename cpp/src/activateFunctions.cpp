// activateFunction.cpp

#include "../include/activateFunctions.h"
#include <cmath>
#include <cstdlib>

double Relu(const double x) {
  if (x < 0) {
    return 0.0;
  } else {
    return x;
  }
}

double Sigmoid(double x) {
  return 1.0 / (1.0 + std::exp(-x));
}

double Tanh(double x) {
  return std::tanh(x);
}

double genRandomValue() {
  srand((unsigned) time(NULL));
  return (double) rand()/RAND_MAX;
}
