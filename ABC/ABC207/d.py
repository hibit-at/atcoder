from fractions import Fraction

n = int(input())
s = []
t = []
for i in range(n):
    s.append(tuple(map(int, input().split(' '))))
for i in range(n):
    t.append(tuple(map(int, input().split(' '))))

sgx = sum(s[i][0] for i in range(n))
sgx *= Fraction(1, n)
sgy = sum(s[i][1] for i in range(n))
sgy *= Fraction(1, n)
sg = (sgx, sgy)

tgx = sum(t[i][0] for i in range(n))
tgx *= Fraction(1, n)
tgy = sum(t[i][1] for i in range(n))
tgy *= Fraction(1, n)
tg = (tgx, tgy)

X = [(s[i][0] - sg[0], s[i][1] - sg[1]) for i in range(n)]
Y = [(t[i][0] - tg[0], t[i][1] - tg[1]) for i in range(n)]


def normsq(p):
    return p[0]**2 + p[1]**2


if min(s) == max(s) and min(t) == max(t):  # 1つの場所に複数の点が重なっている？
    print('Yes')
    exit()

for i in range(n):
    for j in range(n):
        if normsq(X[i]) != normsq(Y[j]):
            continue
        if normsq(X[i]) == 0:
            continue
        a, b = X[i]
        c, d = Y[j]
        cos = Fraction(a*c+b*d, a*a+b*b)
        sin = -Fraction(a*d-b*c, a*a+b*b)
        Z = [(cos*Y[i][0] - sin*Y[i][1], sin*Y[i][0]+cos*Y[i][1])
             for i in range(n)]
        if sorted(Z) == sorted(X):
            print('Yes')
            exit()
print('No')
