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
  std::vector<Weight> Weights;

  public:
  Neuron();
  ~Neuron();
  void setInput(double input);
  double getInput();
  void setOutput(double output);
  double getOutput();
  std::vector<Weight> getWeights();
  bool connectWeights(unsigned short int numberOfConnection);
};

class Layer {
  private:
  std::vector<Neuron> Neurons;
  public:
  Layer();
  ~Layer();
  std::vector<Neuron> getNeurons();
  bool fillLayer(unsigned short int numberOfNeurons);
  unsigned short int getNumberOfNeurons();
};

class NeuralNetwork {
  private:
  Layer inputLayer;
  std::vector<Layer> hiddenLayers;
  Layer outputLayer;

  public:
  NeuralNetwork();
  ~NeuralNetwork();
  bool buildNeuralNetwork(std::vector<unsigned short int> morfology);
  int getNumberNextLayer(unsigned short int layerIndex);
  bool connecLayers();
  bool FeedFoward(std::vector<double> inputs);
  bool BackPropagation();
  double getAccuracy(std::vector<double> predictedValue, std::vector<double> realValue);
};

#endif //COMPONENTS_H
