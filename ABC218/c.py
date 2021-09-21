from os import stat
import numpy as np
from scipy import stats

n = int(input())
s = [input() for _ in range(n)]
t = [input() for _ in range(n)]

sx = []
sy = []
sz = []
tx = []
ty = []
tz = []

for i in range(n):
    for j in range(n):
        if s[i][j] == '#':
            sx.append(i)
            sy.append(j)
        if t[i][j] == '#':
            tx.append(i)
            ty.append(j)

for i in range(2):

    gsx = np.var(sx)
    gsy = np.var(sy)
    covs = np.cov(sx,sy)
    gtx = np.var(tx)
    gty = np.var(ty)
    covt = np.cov(tx,ty)

    eps = 1e-6

    sub1 = abs(gsx-gtx) < eps
    sub2 = abs(gsy-gty) < eps
    sub3 = (abs(covs-covt) < eps).all()

    if sub1 and sub2 and sub3:
        print('Yes')
        exit()

    tx = np.array(tx)
    ty = np.array(ty)
    tx,ty = -ty,tx
        
print('No')