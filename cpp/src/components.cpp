// components.cpp

#include "../include/components.h"
#include <cstdlib>
#include <iostream>
#include <exception>
#include <stdexcept>
#include <vector>

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
  this->Weights = std::vector<Weight>();
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

std::vector<Weight> Neuron::getWeights() {
  return this->Weights;
}

bool Neuron::connectWeights(unsigned short int numberOfConnections) {
  try {
    for (int i = 0; i < numberOfConnections; ++i) {
      this->Weights.emplace_back(Weight());
    } 
  } catch (const std::exception& e) {
    std::cerr << "Error in connectWeights: " << e.what() << std::endl;
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

bool Layer::fillLayer(unsigned short int numberOfNeurons) {
  try {
    for (int i = 0; i < numberOfNeurons; ++i) {
      this->Neurons.emplace_back(Neuron());
    }
  } catch (const std::exception& e) {
    std::cerr << "Error in fillLayer: " << e.what() << std::endl;
    return false;
  }
  return true;
}

std::vector<Neuron> Layer::getNeurons() {
  return Neurons;
}
unsigned short int Layer::getNumberOfNeurons() {
  return Neurons.size();
}

// NeuralNetwork 

NeuralNetwork::NeuralNetwork() {
  this->inputLayer = Layer();
  this->hiddenLayers = std::vector<Layer>();
  this->outputLayer = Layer();
}

NeuralNetwork::~NeuralNetwork() {
   this->inputLayer;
  this->hiddenLayers.clear();
   this->outputLayer;
}

int NeuralNetwork::getNumberNextLayer(unsigned short int layerIndex) {
  if (layerIndex == 0) {
    return this->hiddenLayers.at(0).getNumberOfNeurons();
  } else if (layerIndex > 0 && layerIndex < this->hiddenLayers.size()) {
    return this->hiddenLayers.at(layerIndex).getNumberOfNeurons();
  } else if (layerIndex == this->hiddenLayers.size()) {
    return this->outputLayer.getNumberOfNeurons();
  } else {
    return 0;
  }
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

    // this->inputLayer()
    // this->hiddenLayers.clear();
    // this->outputLayer;

    return false;
  }
  return true;
}

bool NeuralNetwork::connecLayers() {
  this->inputLayer.fillLayer(0);
  unsigned short int numberInNextLayer;
  
  for (Layer hiddenlayer: this->hiddenLayers) {
    for (unsigned short int i = 0; i < hiddenlayer.getNumberOfNeurons(); ++i) {
      numberInNextLayer = getNumberNextLayer(i+1);
      hiddenlayer.getNeurons().at(i).connectWeights(numberInNextLayer);
    }
  }
  return true;
}

bool NeuralNetwork::FeedFoward(std::vector<double> inputs) {
  if (this->inputLayer.getNumberOfNeurons() != inputs.size()) {
    std::cerr << "Invalid number of inpust" << std::endl;
    return false;
  } else {
    Neuron currentlyNeuron;
    for (size_t i = 0; i < inputs.size(); ++i) {
      currentlyNeuron = this->inputLayer.getNeurons().at(i);
      currentlyNeuron.setInput(inputs.at(i));
      for (Weight weight: currentlyNeuron.getWeights()) {
        weight.multiplyValue(currentlyNeuron.getInput());
      }
    }
    for (Layer hiddenlayer: this->hiddenLayers) {

    }
  }
  return true;
}
