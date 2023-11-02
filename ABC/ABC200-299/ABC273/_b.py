from decimal import ROUND_HALF_UP, Decimal
x,k = list(map(int, input().split(' ')))
x = Decimal(x)

for i in range(k):
    x = x.quantize(Decimal(-i),rounding=ROUND_HALF_UP)
    print(x)

print(x)