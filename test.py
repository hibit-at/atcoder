import numpy as np

a = np.eye(10)
a[1][0:4] = np.ones(4)
print(a[1][0:4])
