x = input()
m = int(input())

n = len(x)
if n == 1:
    nowd = int(x)
    if nowd <= m:
        print(1)
        exit()
    else:
        print(0)
        exit()

d = 0
for i in range(n):
    d = max(d, int(x[i]))

a = []
for c in x:
    a.append(int(c))
a.reverse()

ok = 0
ng = pow(10, 18)+1

while abs(ok-ng) > 1:
    mid = (int)((ok+ng)/2)
    total = 0
    for i in range(n):
        nowd = int(x[i])
        if total > pow(10,18):
            ng = mid
            continue
        total += nowd*pow(mid,i)
    if total <= m:
        ok = mid
    else:
        ng = mid

print (max(ok-d,0))
