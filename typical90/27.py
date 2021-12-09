n = int(input())
check = {}
for i in range(n):
    s = input()
    if s in check:
        continue
    else:
        print(i+1)
        check[s] = True
