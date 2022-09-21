test = int(input())

for i in range(test):
    n = int(input())
    s = input().replace('G','X').replace('B','X')
    t = input().replace('G','X').replace('B','X')
    # print(s,t)
    if s == t:
        print('YES')
    else:
        print('NO')