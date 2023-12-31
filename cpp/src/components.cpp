// components.cpp

#include "../include/components.h"
#include "../include/activateFunctions.h"

#include <cstdlib>
#include <iostream>
#include <exception>
#include <stdexcept>
#include <vector>

// Weight

Weight::Weight() {
  this->weight = genRandomValue();
}

Weight::~Weight() {}

void Weight::setWeight(double weight) {
  this->weight = weight;
}

double Weight::getWeight() const{
  return this->weight;
}

bool Weight::multiplyValue(double value) {
  try {
    value *= this->weight;
  } catch (const std::exception& e) {
    std::cerr << "Error in multiplyValue from Weight\n" << e.what() << std::endl;
    return false;
  }
  return true;
}

// Neuron

Neuron::Neuron() {
  this->input = 0;
  this->output = 0;
  this->weights = std::vector<Weight>();
}

Neuron::~Neuron(){}

void Neuron::setInput(double input) {
  this->input = input;
}

double Neuron::getInput() const {
  return this->input;
}

void Neuron::setOutput(double output) {
  this->output = output;
}

double Neuron::getOutput() const {
  return this->output;
}

std::vector<Weight> Neuron::getWeights() const{
  return this->weights;
}

bool Neuron::connectWeights(unsigned short int numberOfConnections) {
  std::cout << "Executing connectWeights" << std::endl;
  try {
    this->weights.clear();
    for (unsigned short int i = 0; i < numberOfConnections; ++i) {
      Weight weight;
      weights.push_back(weight);
    }
  } catch (const std::exception& e) {
    std::cerr << "Error in connectWeights from Neuron\n" << e.what() << std::endl;
    return false;
  }
  return true;
}

// Layer

Layer::Layer() {
  this->Neurons = std::vector<Neuron>();
}

Layer::~Layer() {
  this->Neurons.clear();
}

std::vector<Neuron> Layer::getNeurons() const {
  return this->Neurons;
}

bool Layer::fillLayer(unsigned short int numberOfNeurons) {
  try {
    for (unsigned short int i = 0; i < numberOfNeurons; ++i) {
      this->Neurons.emplace_back(Neuron());
    }
  } catch (const std::exception& e) {
    std::cerr << "Error in fillLayer: " << e.what() << std::endl;
    return false;
  }
  return true;
}

// NeuralNetwork 

NeuralNetwork::NeuralNetwork() {
  this->inputLayer = Layer();
  this->hiddenLayers = std::vector<Layer>();
  this->outputLayer = Layer();
}

NeuralNetwork::~NeuralNetwork() {
  this->hiddenLayers.clear();
}

bool NeuralNetwork::initializeWeigths() {
  std::cout << "Executing initializeWeigths" << std::endl;
  try {
    for (Neuron neuron: this->inputLayer.getNeurons()) {
      for (Weight weight: neuron.getWeights()) {
        weight.setWeight(genRandomValue());
      }
    }

    // I am sorry for making three for's :(
    for (Layer layer: this->hiddenLayers) {
      for (Neuron neuron: layer.getNeurons()) {
        for (Weight weight: neuron.getWeights()) {
          weight.setWeight(genRandomValue());
        }
      }
    }
    
    // Not sure if in outputLayer is needed
    for (Neuron neuron: this->outputLayer.getNeurons()) {
      for (Weight weight: neuron.getWeights()) {
        weight.setWeight(genRandomValue());
      }
    }
  } catch (const std::exception& e) {
    std::cerr << "Error in initializeWeigths from NeuralNetwork\n" << e.what() << std::endl;
    return false;
  }
  return true;
}

bool NeuralNetwork::initializeBiases() {
  // Same logic from above
  std::cout << "Executing initializeBiases" << std::endl;
  try {
    for (Neuron neuron: this->inputLayer.getNeurons()) {
      for (Weight weight: neuron.getWeights()) {
        weight.setWeight(2.0); // For now I am setting as 2
      }
    }

    for (Layer layer: this->hiddenLayers) {
      for (Neuron neuron: layer.getNeurons()) {
        for (Weight weight: neuron.getWeights()) {
          weight.setWeight(2.0);
        }
      }
    }
    
    for (Neuron neuron: this->outputLayer.getNeurons()) {
      for (Weight weight: neuron.getWeights()) {
        weight.setWeight(2.0);
      }
    }
  } catch (const std::exception& e) {
    std::cerr << "Error in initializeBiases from NeuralNetwork\n" << e.what() << std::endl;
    return false;
  }
  return true;
}

bool NeuralNetwork::connectLayers() {
  return true;
}

bool NeuralNetwork::buildNeuralNetwork(std::vector<unsigned short int> morfology) {
  try {
    if (morfology.size() < 2) {
      throw std::runtime_error("No morfology accpeted");
    }

    this->inputLayer.fillLayer(morfology[0]);

    this->hiddenLayers.clear();
    for (size_t i = 1; i < morfology.size() - 1; ++i) {
      this->hiddenLayers.emplace_back();
      this->hiddenLayers.back().fillLayer(morfology[i]);
    }

    outputLayer.fillLayer(morfology.back());

  } catch (const std::exception& e) {
    std::cerr << "Error in buildNeuralNetwork: " << e.what() << std::endl;
    return false;
  }
  return true;
}

bool NeuralNetwork::FeedFoward(std::vector<double> inputs) {
  return true;
}
