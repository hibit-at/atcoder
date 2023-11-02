import itertools
n = int(input())

p = list(map(int, input().split(' ')))
q = list(map(int, input().split(' ')))

p = tuple(p)
q = tuple(q)

sorted_p = sorted(p)

all_case = list(itertools.permutations(sorted_p, n))

print(abs(all_case.index(q) - all_case.index(p)))
