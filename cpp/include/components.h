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
  double getWeight() const;
  bool multiplyValue(double value);
};

class Neuron {
  private:
  double input;
  double output;
  double bias;
  std::vector<Weight> weights;

  public:
  Neuron();
  ~Neuron();
  void setInput(double input);
  double getInput() const;
  void setOutput(double output);
  double getOutput() const;
  void setBias(double bias);
  double getBias() const;
  std::vector<Weight> getWeights() const;
};

class Layer {
  private:
  std::vector<Neuron> Neurons;

  public:
  Layer();
  ~Layer();
  std::vector<Neuron> getNeurons() const;
  bool fillLayer(unsigned short int numberOfNeurons);
};

class NeuralNetwork {
  private:
  Layer inputLayer;
  std::vector<Layer> hiddenLayers;
  Layer outputLayer;

  public:
  NeuralNetwork();
  ~NeuralNetwork();
  bool initializeWeigths();
  bool initializeBiases();
  bool connectLayers();
  std::vector<Layer>& getLayers();
  bool FeedFoward(std::vector<double> inputs);
  bool BackPropagation();
  double getAccuracy(std::vector<double> predictedValue, std::vector<double> realValue);
  bool buildNeuralNetwork(std::vector<unsigned short int> morfology);
};

#endif //COMPONENTS_H
