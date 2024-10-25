n,t,a = list(map(int, input().split(' ')))

rest = n - t - a
# print(f'{rest=}')

if (t+rest > a) and (a+rest > t):
    print('No')
else:
    print('Yes')