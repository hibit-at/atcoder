contest = ['ABC','ARC','AGC','AHC']

dic = {}

for c in contest:
    dic[c] = True

for i in range(3):
    s = input()
    dic[s] = False

for d in dic.items():
    if dic[d[0]]:
        print(d[0])