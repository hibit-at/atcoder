from itertools import permutations
import numpy as np

ax, ay = list(map(int, input().split(' ')))
bx, by = list(map(int, input().split(' ')))
cx, cy = list(map(int, input().split(' ')))
dx, dy = list(map(int, input().split(' ')))


A, B, C, D = map(np.array, [[ax, ay], [bx, by], [cx, cy], [dx, dy]])


def outer(A, B, C):
    AB = B - A
    AC = C - A
    a = AB[0]
    b = AB[1]
    c = AC[0]
    d = AC[1]
    return a*d - b*c


# print(outer(A, B, C))
# print(outer(B, C, D))
# print(outer(C, D, A))
# print(outer(D, A, B))

if outer(A, B, C) < 0:
    print('No')
    exit()
if outer(B, C, D) < 0:
    print('No')
    exit()
if outer(C, D, A) < 0:
    print('No')
    exit()
if outer(D, A, B) < 0:
    print('No')
    exit()

print('Yes')
