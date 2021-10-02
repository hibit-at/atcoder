l, r = map(int, input().split())

mod = int(pow(10, 9)+7)

def solve(a):
    ans = 0

    for i in range(1, 20):
        border = int(pow(10, i-1)) - 1
        count = max(0, a - border)
        ans += count * (count + 1) // 2
        ans += border * count
        ans %= mod

    return int(ans)


ans = solve(r) - solve(l-1)
ans %= mod
print(ans)
