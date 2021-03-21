n = int(input())

ans = 0

for i in range(1,1000001):
    j = str(i)+str(i)
    j = int(j)
    if j <= n:
        ans += 1

print(ans)