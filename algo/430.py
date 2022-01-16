import itertools
n,L,R = list(map(int,input().split(' ')))
print(len(list(itertools.combinations(range(L,R+1),n))))