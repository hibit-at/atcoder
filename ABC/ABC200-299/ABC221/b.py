s = input()
t = input()

n = len(s)

if s == t:
    print('Yes')
    exit()

for i in range(n-1):
    new_s = s[:i] + s[i+1] + s[i] + s[i+2:]
    if new_s == t:
        print('Yes')
        exit()

print('No')