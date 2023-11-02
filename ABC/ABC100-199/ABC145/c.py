import itertools
import math

n = int(input())

points = []

for i in range(n):
    x, y = list(map(int, input().split(' ')))
    points.append((x, y))

ans = 0


def distance(p, q):
    ss = (p[0]-q[0])**2+(p[1]-q[1])**2
    return math.sqrt(ss)


for i in itertools.permutations(range(n), 2):
    p_from = points[i[0]]
    p_to = points[i[1]]
    ans += distance(p_from, p_to)

print(ans/n)
