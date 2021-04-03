n = int(input())
x,y = map(float,input().split(" "))
p,q = map(float,input().split(" "))

import numpy as np

start = np.array((x,y))
target = np.array((p,q))
middle = (start+target)/2
arm = start - middle

ang = 2*np.pi/n

rot = np.array([[np.cos(ang),-np.sin(ang)],[np.sin(ang),np.cos(ang)]])

ans = middle + np.matmul(rot,arm)
print(ans[0],ans[1])