from tensorflow import keras
import numpy as np

w_i_h = np.random.uniform(-0.5, 0.5, (20, 784))
w_h_o = np.random.uniform(-0.5, 0.5, (10, 20))
b_i_h = np.zeros((20, 1))
b_h_o = np.zeros((10, 1))

mnist = keras.datasets.mnist

(images_train, labels_train), (images_test, labels_test) = mnist.load_data()

# Normalizing
images_train, images_test = images_train / 255.00, images_test / 255.00 

# One hot encoded
ohe_labels_train = np.zeros((len(labels_train), 10))
ohe_labels_train[np.arange(len(labels_train)), labels_train] = 1

ohe_labels_test = np.zeros((len(labels_test), 10))
ohe_labels_test[np.arange(len(labels_test)), labels_test] = 1

learn_rate = 0.01
nr_correct = 0
epochs = 3
for epoch in range(epochs):
    for img, l in zip(images_train, ohe_labels_train):
        img = img.reshape(-1, 1)
        l = l.reshape(-1, 1)
        # Forward propagation input -> hidden
        h_pre = b_i_h + w_i_h @ img
        h = 1 / (1 + np.exp(-h_pre))
        # Forward propagation hidden -> output
        o_pre = b_h_o + w_h_o @ h
        o = 1 / (1 + np.exp(-o_pre))

        # Cost / Error calculation
        e = 1 / len(o) * np.sum((o - l) ** 2, axis=0)
        nr_correct += int(np.argmax(o) == np.argmax(l))

        # Backpropagation output -> hidden (cost function derivative)
        delta_o = o - l
        w_h_o += -learn_rate * delta_o @ np.transpose(h)
        b_h_o += -learn_rate * delta_o
        # Backpropagation hidden -> input (activation function derivative)
        delta_h = np.transpose(w_h_o) @ delta_o * (h * (1 - h))
        w_i_h += -learn_rate * delta_h @ np.transpose(img)
        b_i_h += -learn_rate * delta_h

    # Show accuracy for this epoch
    print(f"Acc: {round((nr_correct / images_train.shape[0]) * 100, 2)}%")
    nr_correct = 0
