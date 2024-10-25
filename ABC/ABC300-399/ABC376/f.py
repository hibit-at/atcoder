n, q = list(map(int, input().split(' ')))

L = 0
R = 1

for _ in range(q):
    h, t = list(map(str, input().split(' ')))
    t = int(t)
    print(h,t)