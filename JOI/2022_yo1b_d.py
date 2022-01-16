n = int(input())
a = list(map(int, input().split(' ')))
from collections import defaultdict
d = defaultdict(int)
for x in a:
    d[x] += 1
ans = sorted(d.items(), key=lambda x : (x[1],x[0]))
print(ans[0][0])