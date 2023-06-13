import numpy as np
import matplotlib.pyplot as plt

import sys

filename = sys.argv[1]

image = np.genfromtxt(filename, delimiter=',')
plt.imshow(image, aspect=image.shape[1]/image.shape[0], cmap='gray')
plt.colorbar()
plt.grid()
plt.show()

