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
