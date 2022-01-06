import re
s = input()

pat = r'^\d{3}-\d{4}$'
res = re.match(pat,s)
if res:
    print('Yes')
else:
    print('No')
