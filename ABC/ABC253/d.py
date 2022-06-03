n, a, b = list(map(int, input().split(' ')))


def sum(n, a):
    size = n//a
    return a*size*(size+1)//2


ans = sum(n, 1) - sum(n, a) - sum(n, b) + sum(n, a*b)
print(ans)
