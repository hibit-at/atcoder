import itertools 

h,w = list(map(int, input().split(' ')))
a = [[] for i in range(h)]
for i in range(h):
    a[i] = list(map(int, input().split(' ')))

print(a)

way = 'R'*(h-1) + 'D'*(w-1)

for state in itertools.permutations(way,r=h+w-2):
    print(state)
    record = []
    cx = 0
    cy = 0
    record.append(a[cx][cy])
    for i in range(h+w-2):
        if state[i] == 'R':
            cx += 1
        else:
            cy += 1
        record.append(a[cx][cy])
    print(record)