n = int(input())

def dfs(tmp, s, length):
    if length > 120:
        return
    if tmp > n:
        return
    if tmp == n:
        print(s)
        exit()
    dfs(tmp+1, s+'A', length+1)
    dfs(tmp*2, s+'B', length+1)


dfs(1, 'A', 1)
