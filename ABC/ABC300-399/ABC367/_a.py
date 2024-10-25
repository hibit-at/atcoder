a,b,c = list(map(int, input().split(' ')))
# print(b,c)
if c < b:
    if c < a and a < b:
        print('Yes')
    else:
        print('No')
else:
    if a < b or c < a:
        print('Yes')
    else:
        print('No')