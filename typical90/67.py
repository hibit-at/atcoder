def base8(s):
    t = ''.join(reversed(s))
    cnt = 0
    ans = 0
    for c in t:
        ans += int(c)*(8**cnt)
        cnt += 1
    return ans

def base9(s):
    s = int(s)
    cnt = 0
    ans = ''
    while s:
        ans += str(s%9)
        s //= 9
    t_ans = ''.join(reversed(ans))
    return t_ans

n,k = input().split()

k = int(k)

if n == '0':
    print(0)
    exit()

for _ in range(k):
    n = base8(n)
    n = base9(n)
    n = n.replace('8','5')

print(n)
