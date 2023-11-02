a, b = input().split(' ')
c = str(int(a) + int(b))
a = a.zfill(len(c))
b = b.zfill(len(c))

for x, y, z in zip(a, b, c):
    if int(x) + int(y) != int(z):
        print('Hard')
        exit()

print('Easy')
