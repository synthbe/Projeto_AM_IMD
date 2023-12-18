#include <vector>
#include <time.h>

#include "classes.h"

// -------------- Weight -----------

Weight::Weight(double weight){
    this->weight = weight;
}
double Weight::getWeight(){
    return this->weight;
}

// -------------- Neuron -----------

Neuron::Neuron(int connections){
    this->connections = connections;
    this->weights.resize(this->connections);

    for (int i = 0; i < this->connections; ++i){
        weights[i] = Weight()
    }
    
};

void Neuron::setOutput(double output){
    this->output = output;
}
double Neuron::getOutput(){
    return this->output;
}

void Neuron::setError(double error){
    this->error = error;
}
double Neuron::getError(){
    return this->error;
}

int Neuron::getConnections(){
    return this->connections;
}

// ------------------ Layer -------------

Layer::Layer(int manyNeurons){
    this->manyNeurons = manyNeurons;
    this->Neurons.resize(manyNeurons);

    for (int i = 0; i < manyNeurons; ++i){
        Neurons[i] = Neuron();
    }
}
int Layer::getManyNeurons(){
    return this->manyNeurons;
}

// ------------------ Neural Network ---------

Neural_Network::Neural_Network(int input, int hidden, int inhidden, int output){
    this->input = input;
    this->hidden = hidden;
    this->inhidden = inhidden;
    this->output = output;
    
    this->intputLayer = Layer(this->input);
    
    HiddenLayers.resize(this->hidden);
    for (int i = 0; i < this->hidden; ++i){
        HiddenLayers[i] = Layer(this->inhidden);
    }

    this->outputLayer = Layer(this->output);
}

void Neural_Network::connectNeurons(){
    for (int i = 0; i < )
}