import re
s = input()
L, R = list(map(int, input().split(' ')))

pat = r'^0+[1-9]'
res = re.match(pat, s)

if res:
    print('No')
    exit()

pat = r'^0+$'
res = re.match(pat, s)

if res:
    if len(s) > 1:
        print('No')
        exit()

s = int(s)

if L <= s and s <= R:
    print('Yes')
else:
    print('No')
