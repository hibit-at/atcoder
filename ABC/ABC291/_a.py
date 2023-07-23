s = input()

n = len(s)

for i in range(n):
    if s[i].isupper():
        print(i+1)
        exit()