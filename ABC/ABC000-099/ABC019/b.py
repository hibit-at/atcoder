import itertools

s = input()

groups = itertools.groupby(s)

ans = ''

for k, g in groups:
    ans += str(k)
    ans += str(len(list(g)))

print(ans)