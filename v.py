n = int(input())

to = [[] for i in range(n)]

for i in range(n-1):
    u,v = list(map(int, input().split(' ')))
    u -= 1
    v -= 1
    to[u].append(v)
    to[v].append(u)