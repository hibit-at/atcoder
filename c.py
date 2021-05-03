from collections import deque

import numpy as np

n, a, b = map(int, input().split())

# バージョンをグラフノードとみなし、隣接行列toでネットワーク関係を保持
to = [[] for _ in range(n+1)]
for i in range(n):
    commit = input().split()
    if commit[0] == 'UPDATE':
        parent = int(commit[1])
        child = i+1
        to[parent].append(child)
    if commit[0] == 'MERGE':
        parent1 = int(commit[1])
        parent2 = int(commit[2])
        child = i+1
        to[parent1].append(child)
        to[parent2].append(child)

# クリーンなバージョンと、バグ確定のバージョンを保持しておく
isClean = [False]*(n+1)
isBug = [False]*(n+1)
p_vector = list(map(int, input().split()))
q_vector = list(map(int, input().split()))
for p in p_vector:
    isClean[p] = True
for q in q_vector:
    isBug[q] = True

# 全探索を行う
# 計算量はO(n^2)なので、今回の制約ならば安全
# あるノードから辿る道筋に...
# 条件1「クリーンノードが1つでも含まれる」場合
# バグの子はバグを引き継ぐため、これが最初のバグであはありえない
# 条件2「バグ確定ノードをすべて含む」場合
# これは最初のバグである可能性がある。ただし条件1の場合はその限りではない
# つまり、条件1を満たさない場合かつ条件2を満たす場合、最初のバグノードの可能性がある

ans = 0
for i in range(n+1):
    if isClean[i]:
        continue
    # 条件1のチェック
    noClean = True
    # 条件2のチェック
    bug_hit = 0
    que = deque()
    que.append(i)
    isVisited = [False]*(n+1)
    while que:
        now = que.popleft()
        if isBug[now]:
            bug_hit += 1
        if isClean[now]:
            noClean = False
        for next in to[now]:
            if isVisited[next]:
                continue
            que.append(next)
            isVisited[next] = True
    if bug_hit == b and noClean:
        ans += 1

print(ans)
