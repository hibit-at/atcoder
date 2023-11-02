n = int(input())
s = input()
for i in range(n-2):
    t = s[i:i+3]
    # print(t)
    if t == 'ABC':
        print(i+1)
        exit()
print(-1)