import itertools

s,k = list(input().split())
k = int(k)

ans = []

for case in itertools.permutations(s,len(s)):
    ans.append(case)

ans = set(ans)
ans = list(ans)
ans.sort()

print(''.join(ans[k-1]))
