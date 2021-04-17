s = input()

for i in range(100):
    prefix = '0'*i
    t = prefix + s
    # print(t)
    if t == t[::-1]:
        print('Yes')
        exit()

print('No')