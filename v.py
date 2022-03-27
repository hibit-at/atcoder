import re

s = input().split(' ')
# print(s)
n = int(input())
t = [input().replace('*','.') for _ in range(n)]
# print(t)

ans = []

for ss in s:
    okay = False
    for tt in t:
        res = re.fullmatch(tt,ss)
        if(res):
            okay = True
            ans.append('*'*len(ss))
            break
    if okay:
        continue
    ans.append(ss)

print(' '.join(ans))