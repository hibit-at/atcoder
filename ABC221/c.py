import itertools

n = input()

m = [0,1]

ans = 0

for case in itertools.product(m,repeat=len(n)):
    p = ''
    q = ''
    for nn,c in zip(n,case):
        if c == 0:
            p += nn
        if c == 1:
            q += nn
    if p == '':
        continue
    if q == '':
        continue
    p = sorted(p,reverse=True)
    p = ''.join(p)
    q = sorted(q,reverse=True)
    q = ''.join(q)
    p = int(p)
    q = int(q)
    ans = max(ans,p*q)

print(ans)