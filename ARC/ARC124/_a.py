n, K = list(map(int, input().split(' ')))
imos = [0] * (n+1)
free = [True] * n
for i in range(K):
    c, k = input().split(' ')
    k = int(k)
    k -= 1
    free[k] = False
    if c == 'R':
        imos[0] += 1
        imos[k+1] -= 1
    if c == 'L':
        imos[k] += 1
        imos[n] -= 1
dp = [0] * (n+1)
for i in range(n):
    dp[i] = imos[i]
    if i > 0:
        dp[i] += dp[i-1]
ans = 1
for i in range(n):
    if free[i]:
        ans *= dp[i]
        ans %= 998244353
print(ans)
