import sys
import numpy as np
from scipy import ndimage
import matplotlib.pyplot as plt

data = np.load(sys.argv[1])

plt.imshow(data, cmap='seismic')
plt.show()