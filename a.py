import itertools
n, m, k = map(int, input().split())

w = 'w'*n
b = 'b'*m


ans = 0

for case in itertools.permutations(w+b,r=n+m):
    s = ''.join(case)
    key = 'w'*(k+1)
    print(s,key)
    if key in s:
        continue
    ans += 1

print(ans)