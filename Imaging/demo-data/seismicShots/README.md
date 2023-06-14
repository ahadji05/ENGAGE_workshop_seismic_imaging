This is the directory to store seismic data in numpy files. The name of the files indicates the location of the source (source-index) and the size of the model in x-direction (nx).

The ***prefix*** for the name of the files should be "seis", then the two values are separated by ***underscore*** "\_", and finally the ***extension*** of the numpy files is ".npy"

For example, "seis500\_1001.npy" is a file that contains a seismic shot that is fired from position with source-index=500 in a model of size nx=1001 points. The source-index cannot be larger than nx.

The directory may contain one or more files as long as all of them adhere to the same prefix, extension, and NX, and have a meaningfull source-index, e.g.:
 - "seis100\_501.npy"
 - "seis200\_501.npy"
 - "seis300\_501.npy"
 - "seis400\_501.npy"
 - ...
