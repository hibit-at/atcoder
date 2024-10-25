from collections import deque

def bfs(graph, start):
    dist = [float('inf')] * len(graph)
    queue = deque()
    dist[start] = 0
    queue.append(start)
    while queue:
        u = queue.popleft()
        for v in graph[u]:
            if dist[v] == float('inf'):
                dist[v] = dist[u] + 1
                queue.append(v)
    return dist

def find_shortest_cycle(N, edges):
    graph = [[] for _ in range(N)]
    rev_graph = [[] for _ in range(N)]
    for u, v in edges:
        graph[u].append(v)
        rev_graph[v].append(u)
    dist1 = bfs(graph, 0)  # 頂点1からの距離
    dist2 = bfs(rev_graph, 0)  # 頂点1への距離
    min_cycle = float('inf')
    for u in range(N):
        # 頂点uから頂点1へのサイクル
        if dist1[u] != float('inf') and dist2[u] != float('inf') and u != 0:
            min_cycle = min(min_cycle, dist1[u] + dist2[u])
    for u in range(N):
        for v in graph[u]:
            if dist1[u] != float('inf') and dist2[v] != float('inf') and u != v:
                min_cycle = min(min_cycle, dist1[u] + 1 + dist2[v])
    if min_cycle == float('inf'):
        return -1
    else:
        return min_cycle

n,m = list(map(int, input().split(' ')))
edges = [list(map(int, input().split(' '))) for i in range(m)]
for i in range(m):
    edges[i][0] -= 1
    edges[i][1] -= 1

print(find_shortest_cycle(n,edges))