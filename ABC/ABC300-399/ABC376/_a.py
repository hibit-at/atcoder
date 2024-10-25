n,c = list(map(int, input().split(' ')))

last = -10**18

ans = 0

t = list(map(int, input().split(' ')))


for i in range(n):
    if t[i] - last >= c:
        ans += 1
        last = t[i]

print(ans)