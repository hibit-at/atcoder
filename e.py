n = int(input())
s = input()

if n == 0:
    print(1)
    exit()

def level_check(s):
    size = len(s)
    if size == 0:
        return 0
    if s != s[::-1]:
        return 0
    return 1+dfs(s[:int(size/2)])

if level_check(s) > n:
    print('impossible')
    exit()

def dfs(s,turn):
    if(level_check(s) == n):
        return turn
    