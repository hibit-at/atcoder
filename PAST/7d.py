n = int(input())
s = input()

ans = []

words = ['axa','ixi','uxu','exe','oxo']

def dfs(s):
    cnt = s.count('.')
    ans.append((s,cnt))
    for w in words:
        if w in s:
            dfs(s.replace(w,'...'))

dfs(s)

ans = sorted(ans,key=lambda x : -x[1])

print(ans[0][0])