def dfs(s : str) -> str:
    if s == '':
        return 'YES'
    words = ['ch','o','k','u']
    for word in words:
        if s.endswith(word):
            return dfs(s[:-len(word)])
    return 'NO'

print(dfs(input()))