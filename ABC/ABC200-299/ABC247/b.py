n = int(input())
s = []
t = []
for i in range(n):
    sx, tx = list(input().split(' '))
    s.append(sx)
    t.append(tx)

for i in range(n):
    first_name = s[i]
    second_name = t[i]
    # fisrt_name_check
    isFirstSafe = True
    for j in range(n):
        if i == j:
            continue
        if first_name == s[j] or first_name == t[j]:
            isFirstSafe = False
    # second_name_check
    isSecondSafe = True
    for j in range(n):
        if i == j:
            continue
        if second_name == s[j] or second_name == t[j]:
            isSecondSafe = False
    if not isFirstSafe and not isSecondSafe:
        print('No')
        exit()
print('Yes')

