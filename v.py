s = input()

import itertools

ans = 1e10

for case in itertools.permutations(s,3):
    # print(case)
    j = ''.join(case)
    i = int(j)
    print(i)
    ans = min(ans, abs(753-i))

print(ans)