// components.h

#include <vector>

#ifndef COMPONENTS_H
#define COMPONENTS_H

class Weight {
  private:
  double weight;

  public:
  Weight();
  ~Weight();
  void setWeight(double weight);
  double getWeight();
  bool multiplyValue(double value);
};

class Neuron {
  private:
  double input;
  double output;
  std::vector<Weight> *Weights;

  public:
  Neuron();
  ~Neuron();
  void setInput(double input);
  double getInput();
  void setOutput(double output);
  double getOutput();
  bool connectWeights(int numberOfConnection);
};

class Layer {
  private:
  std::vector<Neuron> *Neurons;
  public:
  Layer();
  ~Layer();
  bool fillLayer(int numberOfNeurons);
};

class NeuralNetwork {
  private:
  Layer *inputLayer;
  std::vector<Layer> *deepLayers;
  Layer *outputLayer;

  public:
  NeuralNetwork();
  ~NeuralNetwork();
  bool buildNeuralNetwork(std::vector<int> morfology);
  bool connecLayers();
  bool FeedFoward();
  bool BackPropagation();
};

#endif //COMPONENTS_H
