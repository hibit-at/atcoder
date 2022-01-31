n = int(input())
tuples = [[] for i in range(n)]
for i in range(n):
    tuples[i] = tuple(input().split(' '))
tuples = set(tuples)
print(len(tuples))
