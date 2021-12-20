import math

h, w = map(int, input().split())

if h == 1 or w == 1:
    print(h*w)
else:
    print(math.ceil(h/2) * math.ceil(w/2))
