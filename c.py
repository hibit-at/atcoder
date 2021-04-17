import math

r,x,y = list(map(int,input().split()))
d = math.sqrt(x*x+y*y)

if d == r:
    print(1)
    exit()
if d <= 2*r:
    print(2)
    exit()
print(math.ceil(d/r))