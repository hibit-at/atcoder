n,k = list(map(int, input().split(' ')))
a = list(map(int, input().split(' ')))
ans = a[-k:] + a[:(n-k)]
print(*ans)