import sys
import numpy as np
from scipy import ndimage
import matplotlib.pyplot as plt

snapshot = sys.argv[1]
model = sys.argv[2]
snapshot_image = np.load(snapshot)
model_image = np.load(model)

vm = np.max(np.abs(snapshot_image))

plt.imshow(model_image, cmap='gray')
plt.imshow(snapshot_image, alpha=0.5, vmin=-vm, vmax=vm, cmap='seismic')
plt.colorbar()
plt.title("Snapshot")
plt.show()