import itertools

n,k=map(int,input().split())

a = range(1,n+1)

a_list =  list(itertools.product(a,repeat=3))

a_list.sort()

print(a_list)

print(a_list[k-1])
