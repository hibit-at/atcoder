a = [0,1,2]

s = list(map(str, input().split(' ')))
ab = int(s[0] == '<')
ac = int(s[1] == '<')
bc = int(s[2] == '<')
# print(ab,ac,bc)

from itertools import permutations

for perm in permutations(a):
    # print(perm)
    # print(perm[0]<perm[1])
    # print(perm[0]<perm[2])
    # print(ab == perm[0]<perm[1])
    if (ab == int(perm[0]<perm[1])) and (ac == int(perm[0]<perm[2])) and bc == int(perm[1]<perm[2]):
        idx = perm.index(1)
        print('ABC'[idx])
        # exit()
    