s = input()
ans = 0
org = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
pos = 0

for i in range(26):
    target = org[i]
    where = s.index(target)
    if i>0:
        ans += abs(where-pos)
    pos = where

print(ans)