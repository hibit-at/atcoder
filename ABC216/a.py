x,y = map(int,input().split('.'))
sign = ''
if y <= 2:
    sign = '-'
elif y <= 6:
    sign = ''
else:
    sign = '+'
print(f'{x}{sign}')