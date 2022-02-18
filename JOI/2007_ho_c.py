import itertools
from collections import defaultdict
import numpy

n = int(input())


isExists = defaultdict(bool)

points = []
for i in range(n):
    x, y = list(map(int, input().split(' ')))
    points.append((x, y))
    isExists[(x, y)] = True


def isSquare(p, q, theta, isExists):
    p = numpy.array(p)
    q = numpy.array(q)
    diff = q-p
    rot_mat = numpy.array(
        [[numpy.cos(theta), numpy.sin(theta)],
         [-numpy.sin(theta), numpy.cos(theta)]])
    diff_rot = numpy.matmul(rot_mat, diff)
    p_plus_diff = p + diff_rot
    q_plus_diff = q + diff_rot
    p_plus_diff = tuple(p_plus_diff)
    q_plus_diff = tuple(q_plus_diff)
    return isExists[p_plus_diff] and isExists[q_plus_diff]


ans = 0

for case in itertools.combinations(range(n), 2):
    p = points[case[0]]
    q = points[case[1]]
    diff_x = p[0] - q[0]
    diff_y = p[1] - q[1]
    if isSquare(p, q, numpy.pi/2, isExists):
        ans = max(ans, diff_x**2 + diff_y**2)
    if isSquare(p, q, -numpy.pi/2, isExists):
        ans = max(ans, diff_x**2 + diff_y**2)

print(ans)