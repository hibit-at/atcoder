
def solve():
    n = int(input())
    ss = []
    for i in range(3):
        ss.append(input())

    import itertools

    for case in itertools.permutations(ss,3):
        print(case)
        
t = int(input())

for i in range(t):
    solve()
