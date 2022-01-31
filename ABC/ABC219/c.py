x = input()

alphabet = ''.join([chr(ord('a')+i) for i in range(26)])

mp = {}

for c,a in zip(x,alphabet):
    mp[c] = a

pairlist = []

n = int(input())

for i in range(n):
    s = input()
    t = ''.join([mp[c] for c in s])
    pairlist.append((s,t))

sort_pl = sorted(pairlist,key=lambda x : x[1])

for s in sort_pl:
    print(s[0])