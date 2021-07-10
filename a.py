<<<<<<< HEAD
import itertools
n, m, k = map(int, input().split())

w = 'w'*n
b = 'b'*m


ans = 0

for case in itertools.permutations(w+b,r=n+m):
    s = ''.join(case)
    key = 'w'*(k+1)
    print(s,key)
    if key in s:
        continue
    ans += 1

print(ans)
=======
from collections import deque

n = int(input())
p,q = deque(),deque()
for i in input().split():
    p.append(int(i))
ans = 0
while p:
    now = p.popleft()
    while(now in q):
        q.popleft()
    q.append(now)
    ans = max(ans,len(q))
print(ans)
>>>>>>> e6d71b39984d79fdb2c10411835c1bca8dab5505
