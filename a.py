import itertools
from collections import defaultdict

s = input()

nums = list(range(10))

ans = 0

for case in itertools.product(nums,repeat=4):
    # print(case,end='')
    mp = defaultdict(bool)
    for i in range(4):
        mp[case[i]] = True
    # outcheck
    outcheck = False
    for i in range(10):
        if s[i] == 'x':
            if mp[i]:
                # print(i,'out')
                outcheck = True
                break
    if outcheck:
        continue
    # hitcheck
    mustcheck = True
    for i in range(10):
        if s[i] == 'o':
            if not mp[i]:
                mustcheck = False
    if mustcheck:
        # print('ok')
        ans += 1

print(ans)
