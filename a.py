import itertools

from scipy.special import comb

k = int(input())

mod = int(pow(10,9))+7

# if k%9 != 0:
#     print(0)
#     exit()

ans = 0
cnt = 0

while k > 0:
    part = 0
    for i in range(cnt+1):
        part += comb(k-i,cnt)*pow(2,k-i-1,mod)*pow(-1,i)
        part %= mod
    ans += part*pow(-1,cnt)
    ans %= mod
    k -= 9
    cnt += 1

print(int(ans))
