a, b, c = map(int, input().split())

tmp = 1

for i in range(b):
    tmp *= c

if a < tmp:
    print('Yes')
else:
    print('No')
