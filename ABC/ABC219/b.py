s = []
for i in range(3):
    s.append(input())
t = input()

ans = ''

for c in t:
    ans += s[int(c) - 1]

print(''.join(ans))