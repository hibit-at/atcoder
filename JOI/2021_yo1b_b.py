import re

n = input()
s = input()
pat = r'.*I.*O.*I.*'
res = re.match(pat,s)
if res:
    print('Yes')
else:
    print('No')
