import numpy as np
import itertools

nums = range(1,3)

for i in list(itertools.product(nums, repeat=8)):
    a, b, c, d, e, f, g, h = i
    mat1 = np.array([[a, b], [c, d]])
    mat2 = np.array([[e, f], [g, h]])
    mat3 = np.matmul(mat1, mat2)
    print('------')
    print(f'{mat1[0]}    {mat2[0]}   {mat3[0]}')
    print(f'{mat1[1]} x  {mat2[1]} = {mat3[1]}')