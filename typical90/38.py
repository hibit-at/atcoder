from math import gcd

a, b = map(int, input().split())

ans = a//gcd(a, b)*b

if ans > int(pow(10, 18)):
    print('Large')
else:
    print(ans)
