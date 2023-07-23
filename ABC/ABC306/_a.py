a = list(map(int, input().split(' ')))

a.reverse()

ans = 0

for i in range(64):
    ans *= 2
    if a[i] == 1:
        ans += 1

print(ans)