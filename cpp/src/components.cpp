// components.cpp

#include "../include/components.h"
#include <iostream>
#include <exception>

// Weight

Weight::Weight() {
  this->weight = 0;
}

Weight::~Weight() {}

void Weight::setWeight(double weight) {
  this->weight = weight;
}

double Weight::getWeight() {
  return this->weight;
}

bool Weight::multiplyValue(double value) {
  try {
    value *= this->weight;
  } catch (const std::exception& e) {
    std::cerr << "Multiply value to weight erro: " << e.what() <<std::endl;
    return false;
  }
  return true;
}

// Neuron

Neuron::Neuron() {
  this->input = 0;
  this->output = 0;
  this-> Weights = std::vector<Weight>();
}

Neuron::~Neuron(){}










