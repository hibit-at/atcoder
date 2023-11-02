from math import cos, pi, sin
import numpy as np
a, b, d = list(map(int, input().split(' ')))
p = np.array([a, b])
degree = d*pi/180
# print(degree)
rot = np.array([[cos(degree), -sin(degree)], [sin(degree), cos(degree)]])
c, d = np.matmul(rot, p)
print(c, d)
