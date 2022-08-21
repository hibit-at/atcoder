from math import cos, pi, sin
import numpy as np
n = int(input())
sx, sy = list(map(int, input().split(' ')))
tx, ty = list(map(int, input().split(' ')))
rad = 2*pi/n
rot = np.array([[cos(rad), -sin(rad)], [sin(rad), cos(rad)]])
V_ot = np.array([tx, ty])
V_ts = np.array([sx, sy]) - V_ot
ans = V_ot + V_ts/2 + np.matmul(rot, V_ts/2)
print(*ans)
