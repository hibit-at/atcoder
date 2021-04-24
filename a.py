n = int(input())
s = input()

s_list = list(s)

q = int(input())

for i in range(q):
    t,a,b = map(int,input().split(' '))
    if t == 1:
        a -= 1
        b -= 1
        s_list[a],s_list[b] = s_list[b],s_list[a]
    if t == 2:
        s_list = s_list[:n] + s_list[n:]
    print(s_list)
