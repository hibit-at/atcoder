import itertools
n,L,R = list(map(int,input().split(' ')))
for case in itertools.combinations_with_replacement(range(L,R+1),n):
    print(' '.join(map(str,case)))