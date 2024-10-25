r = int(input())
next = ((r+99)//100)*100
# print(next)
if r%100 == 0:
    print(100)
else:
    print(next-r)