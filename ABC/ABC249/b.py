s = input()

uppercount = 0
lowercount = 0
from collections import defaultdict
check = defaultdict(int)

for c in s:
    if c.isupper():
        uppercount += 1
    if c.islower():
        lowercount += 1
    check[c] += 1

# print(uppercount)
# print(lowercount)
# print(len(check))

if uppercount > 0 and lowercount > 0 and len(s) == len(check):
    print("Yes")
else:
    print("No")
