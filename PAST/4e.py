n = int(input())
s = input()
r = ''.join(reversed(s))

import itertools

for case in itertools.permutations(s,n):
    t = ''.join(case)
    if t != s and t != r:
        print(t)
        exit()

print('None')