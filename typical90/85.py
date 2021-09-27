def solve(k):
    ans = []
    for a in range(1,k+1):
        for b in range(a,k+1):
            for c in range(b,k+1):
                if a*b*c == k:
                    ans.append((a,b,c))
    return ans

for k in range(1,51):
    print('solve',k)
    ans = solve(k)
    print(' size :',len(ans))
    for a in ans:
        print('  ',a)