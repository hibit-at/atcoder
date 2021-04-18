n,m = map(int,input().split(' '))

a = list(map(int,input().split(' ')))
b = list(map(int,input().split(' ')))

ans = []

for aa in a:
    if aa not in b:
        ans.append(aa)

for bb in b:
    if bb not in a:
        ans.append(bb)

ans.sort()
ans = map(str,ans)

print(' '.join(ans))