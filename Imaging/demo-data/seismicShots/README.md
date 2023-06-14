This is the directory to store seismic data in numpy files. The name of the directory indicates the location of the source (src-X) and the size of the model in x-direction (NX). 

The **prefix** for the name of the files should be "seis", then the two values are separated by **underscore** "\_", and finally the **extension** of the numpy files is ".npy"

For example, "seis500\_1001.npy" is a files that contains a seismic shot fired from position source-index=500 in a model of size nx=1001 points.

The directory may contain one or more files as long as all of them adhere to the same prefix, extension, and NX, and have a meaningfull source-index.

