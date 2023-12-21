// components.cpp

#include "../include/components.h"
#include <cstdlib>
#include <iostream>
#include <exception>
#include <stdexcept>

// Weight

Weight::Weight() {
  srand((unsigned) time(NULL));
  this->weight = (double) rand()/RAND_MAX;
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
  this-> Weights = new std::vector<Weight>();
}

Neuron::~Neuron(){}

void Neuron::setInput(double input) {
  this->input = input;
}

double Neuron::getInput() {
  return this->input;
}

void Neuron::setOutput(double output) {
  this->output = output;
}

double Neuron::getOutput() {
  return this->output;
}

bool Neuron::connectWeights(int numberOfConnections) {
  try {
    for (int i = 0; i < numberOfConnections; ++i) {
      this->Weights->emplace_back(Weight());
    } 
  } catch (const std::exception& e) {
    std::cerr << "Error in connectWeights: " << e.what() << std::endl;
    return false;
    }
  return true;
}

// Layer

Layer::Layer() {
  this->Neurons = new std::vector<Neuron>();
}

Layer::~Layer() {}

bool Layer::fillLayer(int numberOfNeurons) {
  try {
    for (int i = 0; i < numberOfNeurons; ++i) {
      this->Neurons->emplace_back(Neuron());
    }
  } catch (const std::exception& e) {
    std::cerr << "Error in fillLayer: " << e.what() << std::endl;
    return false;
  }
  return true;
}

// NeuralNetwork 

NeuralNetwork::NeuralNetwork() {
  this->inputLayer = new Layer;
  this->deepLayers = new std::vector<Layer>();
  this->outputLayer = new Layer;
}

bool NeuralNetwork::buildNeuralNetwork(std::vector<int> morfology) {
  try {
    if (morfology.size() < 2) {
      throw std::runtime_error("No morfology accpeted");
    }

    this->inputLayer->fillLayer(morfology[0]);

    this->deepLayers->clear();
    for (size_t i = 1; i < morfology.size() - 1; ++i) {
      this->deepLayers->emplace_back();
      this->deepLayers->back().fillLayer(morfology[i]);
    }

    outputLayer->fillLayer(morfology.back());

  } catch (const std::exception& e) {
    std::cerr << "Error in buildNeuralNetwork: " << e.what() << std::endl;

    delete inputLayer;
    delete [] deepLayers;
    delete  outputLayer;

    return false;
  }
  return true;
}

bool NeuralNetwork::connecLayers() {
  this->inputLayer->
}
