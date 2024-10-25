def naive(n,p):
    from collections import defaultdict,deque
    dp = defaultdict(int)
    dp[tuple(p)] = 0
    prev = defaultdict(tuple)
    prev[tuple(p)] = (-1,)
    q = deque()
    q.append(tuple(p))
    while len(q):
        now = q.popleft()
        # print(now)
        for i in range(n-1):
            for j in range(n-1):
                Q = now[:i] + now[i+2:]
                # print(Q)
                next = Q[:j] + now[i:i+2] + Q[j:]
                # print('  ',next)
                if next in dp:
                    continue
                dp[next] = dp[now] + 1
                prev[next] = now
                q.append(next)
    # print(dp)
    # print(prev)
    if tuple(sorted(p)) in dp:
        path = []
        now = tuple(sorted(p))
        while now != (-1,):
            path.append(now)
            now = prev[now]
        return ['Yes', path, dp[tuple(sorted(p))]]
    else:
        return ['No']

def minSwapsToSort(arr):
    n = len(arr)
    # 数列の値と元のインデックスをペアにして、値でソート
    arrpos = [*enumerate(arr)]
    arrpos.sort(key=lambda it:it[1])
    
    # 訪問済みをチェックするための配列
    vis = {i:False for i in range(n)}
    
    ans = 0
    for i in range(n):
        # 既に正しい位置にあるか、訪問済みの場合はスキップ
        if vis[i] or arrpos[i][0] == i:
            continue
        
        cycle_size = 0
        j = i
        # サイクルを見つける
        while not vis[j]:
            vis[j] = True
            j = arrpos[j][0]
            cycle_size += 1
        
        # サイクルが存在する場合、サイクル内の交換回数を加算
        if cycle_size > 0:
            ans += (cycle_size - 1)
    return ans

def solve(n,p):
    min_sort = minSwapsToSort(p)
    # print(min_sort)
    if min_sort%2:
        return ['No']
    else:
        def is_sorted(p):
            for i in range(n-1):
                if p[i] > p[i+1]:
                    return False
            return True
        
        while not sorted(p):
            
            pos = 0
            while p[pos] == pos+1:
                pos += 1
            print(pos)
            
            
        return ['Yes']
    

n = int(input())
p = list(map(int, input().split(' ')))

for x in naive(n,p):
    print(x)
    
n = 4

from itertools import permutations

for perm in permutations(range(1,n+1)):
    print(perm, naive(n, perm), solve(n, perm))
    # assert(naive(n,perm) == solve(n,perm))