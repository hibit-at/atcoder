n = int(input())
a = list(map(int, input().split(' ')))
a.sort()

sq = [i*i for i in range(1000)]

sq = set(sq)

print(sq)

for i in range(1,n):
    for j in range(i):
        ans = a[j]*a[i]
        if ans in sq:
            print(a[j]*a[i])