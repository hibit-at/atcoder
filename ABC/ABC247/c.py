def dfs(n):
    if n == 1:
        return [1]
    return dfs(n-1) + [str(n)] + dfs(n-1)


n = int(input())

print(*dfs(n))