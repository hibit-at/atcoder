import itertools

n = int(input())
a = [[0] * 2 * n for i in range(2*n)]

nums = list(range(0,2*n))

for case in itertools.permutations(nums,2*n):
    continue

print('end')
