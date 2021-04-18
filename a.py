import numpy as np

a,b = map(int,input().split(' '))

A = np.ones(b,dtype='int64')*a
B = np.ones(a,dtype='int64')*-b

print(A,B)

A_sub = np.array(range(a)) - a/2
B_sub = np.array(range(b)) - b/2
A_sub = A_sub.astype('int64')
B_sub = B_sub.astype('int64')

print(A_sub,B_sub)
