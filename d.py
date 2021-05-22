from math import comb


def rec(a, b, k):
    if a+b == 0:
        return
    border = comb(a+b, b, exact=True)*a//(a+b)
    if k < border:
        print('a', end='')
        rec(a-1, b, k)
    else:
        print('b', end='')
        rec(a, b-1, k-border)
    return


a, b, k = map(int, input().split(' '))
rec(a, b, k-1)
