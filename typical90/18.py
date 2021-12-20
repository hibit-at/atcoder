import numpy as np

t = int(input())
l, x, y = map(int, input().split())
q = int(input())
for i in range(q):
    e = int(input())
    if(e % t == 0):
        print(0)
        continue
    rad = 3/2*np.pi - e/t*2*np.pi
    pos = np.array([0, l/2*np.cos(rad), l/2+l/2*np.sin(rad)])
    takahashi = np.array([x, y, 0])
    ground = pos.copy()
    ground[2] = 0
    vector1 = pos - takahashi
    vector2 = ground - takahashi
    inner = np.dot(vector1, vector2)
    inner /= np.linalg.norm(vector1)
    inner /= np.linalg.norm(vector2)
    theta = np.arccos(inner)
    print(theta*360/(2*np.pi))
