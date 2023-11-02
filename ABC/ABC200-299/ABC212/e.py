import numpy as np

mod = 998244353

n, m, k = map(int, input().split(' '))
dist = np.ones((n, n)) - np.eye(n)

for i in range(m):
    u, v = map(int, input().split(' '))
    dist[u-1][v-1] = 0
    dist[v-1][u-1] = 0



def mat_pow_mod(mat,r,mod):
    if r == 0:
        return np.eye(n)
    ans = mat_pow_mod(mat, r//2, mod)
    ans = np.matmul(ans,ans)
    ans %= mod
    if r % 2 == 1:
        ans = np.matmul(ans, mat)
    ans %= mod
    return ans    

tmp = np.eye(n)

for i in range(k):
    ans = mat_pow_mod(dist,i,mod)
    print(int(ans[0][0]),int(tmp[0][0]))
    tmp = np.matmul(tmp,dist)
    tmp %= mod
