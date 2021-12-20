import math

a,b,c = map(int,input().split())
g = math.gcd(math.gcd(a,b),c)
print((a+b+c)//g-3)
