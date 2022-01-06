s = input()
n = len(s)
ans = 0
for i in range(n-1):
    if i%2 == 0:
        ans += int(s[i])*3
    else:
        ans += int(s[i])
if ans%10 == int(s[n-1]):
    print("Yes")
else:
    print("No")