#include <vector>

class Weight{
    private:
        double weight;
    public:
        Weight(double weight);
        double getWeight();
};

class Neuron{
    private:
        std::vector<Weight> weights;
        double output;
        double error;
        int connections;
    public:
        Neuron(int connections);
        void setOutput(double output);
        void setError(double error);
        double getOutput();
        double getError();
        int getConnections();
};

class Layer{
    private:
        std::vector<Neuron> Neurons;
        int manyNeurons;
    public:
        Layer(int manyNeurons);
        int getManyNeurons();
};

class Neural_Network{
    private:
        int input;
        int hidden;
        int inhidden;
        int output;
        Layer intputLayer;
        std::vector<Layer> HiddenLayers;
        Layer outputLayer;
    public:
        Neural_Network(int input, int hidden, int inhidden, int output);
        void connectNeurons();
};