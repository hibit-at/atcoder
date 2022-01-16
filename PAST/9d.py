n = int(input())
a = list(map(int,input().split()))
b = list(map(int,input().split()))
c = []
for i in range(n):
    c.append((a[i]+b[i],a[i],i+1))
c = sorted(c, key=lambda x : (-x[0],-x[1],x[2]))
ans = [str(x[2]) for x in c]
print(' '.join(ans))