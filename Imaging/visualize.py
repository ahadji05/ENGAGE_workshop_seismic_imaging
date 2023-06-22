import numpy as np
import matplotlib.pyplot as plt
import sys

filename = sys.argv[1]

image = np.load(filename)
plt.imshow(image)
plt.show()