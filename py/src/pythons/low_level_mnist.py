from tensorflow import keras
import numpy as np
import matplotlib.pyplot as plt

def Relu(x):
    return np.maximum(0, x)

def derivativeRelu(x):
    return np.where(x < 0, 0, 1)

def Sigmoid(x):
    return 1 / (1 + np.exp(-x))

def derivativeSigmoid(x):
    return 1 - (Sigmoid(x))

def initializeWeights(quantity: int) -> list:
    layers = list()

    inputsWeights = np.random.uniform(-0.5, 0.5, (16, 784))
    layers.append(inputsWeights)

    for _ in range(quantity):
        hiddenLayer = np.random.uniform(-0.5, 0.5, (16, 16))
        layers.append(hiddenLayer)
    
    outputLayer = np.random.uniform(-0.5, 0.5, (10, 16))
    layers.append(outputLayer)

    return layers

def initializeBiases(quantity: int) -> list:
    biases = list()
    for _ in range(quantity):
        bias = np.random.uniform(-0.5, 0.5, (16, 16))
        biases.append(bias)

    outputBias = np.random.uniform(-0.5, 0.5, (10, 16))
    biases.append(outputBias)

    return biases

def getDataset():
    mnist = keras.datasets.mnist

    (images_train, labels_train), (images_test, labels_test) = mnist.load_data()

    # Normalizing
    images_train, images_test = images_train / 255.00, images_test / 255.00 

    # One hot encoded
    ohe_labels_train = np.zeros((len(labels_train), 10))
    ohe_labels_train[np.arange(len(labels_train)), labels_train] = 1

    ohe_labels_test = np.zeros((len(labels_test), 10))
    ohe_labels_test[np.arange(len(labels_test)), labels_test] = 1

    return (images_train, ohe_labels_train), (images_test, ohe_labels_test)

learning_rate = 0.01
epochs = 5
shot, error = 0, 0

if __name__ == "__main__":
    (images_train, labels_train), (images_test, labels_test) = getDataset()
    weights = initializeWeights(5)
    biases = initializeBiases(5)

    # for epoch in range(epochs):
    #     for image, label in zip(images_train, labels_train):
    #
    #
    #
    # for epoch in range(epochs):
    #     for img, label in zip(images_train, ohe_labels_train):
    #         img = img.reshape(-1, 1)
    #         label = label.reshape(-1, 1)
    #
    #         # Foward propagation
    #
    #         hidd_pre = (inp_hidd @ img) + bias_hidd # Input to Hidden
    #         # hidd = np.maximum(0, hidd_pre) # Relu
    #         hidd = 1 / (1 + np.exp(-hidd_pre))
    #
    #         output_pre = (hidd_out @ hidd) + bias_out # Hidden to Output
    #         output = 1 / (1 + np.exp(-output_pre))
    #
    #         # Loss Function
    #
    #         error += np.mean((output - label)**2) # Mean Squared Error
    #         shot += int(np.argmax(output) == np.argmax(label))
    #         
    #         # Back Propagation
    #
    #         delta = output - label
    #         hidd_out += -learning_rate * delta @ np.transpose(hidd)
    #         bias_out += -learning_rate * delta
    #
    #         delta_hidd = np.transpose(hidd_out) @ delta * (hidd * (1 - hidd))
    #         inp_hidd += -learning_rate * delta_hidd @ np.transpose(img)
    #         bias_hidd += -learning_rate * delta_hidd
    #
    #     print(f"Current Epoch: {epoch}")
    #     print(f"Acc: {round((shot / images_train.shape[0]) * 100, 2)}%")
    #     print(f"Loss: {error}")
    #     shot, error = 0, 0
