import string

n,k = list(map(int, input().split(' ')))

s = []

for i in range(n):
    s.append(input())

# print(s)

ans = 0

for i in range(2 ** n):
    tmp = []
    for j in range(n):
        if ((i >> j) & 1):
            tmp.append(s[j])
    # print(tmp)
    from collections import defaultdict
    check = defaultdict(list)
    alphas = list(string.ascii_lowercase)
    # print(alphas)
    for t in tmp:
        for alpha in alphas:
            if alpha in t:
                check[alpha].append(t)
    # print(check)
    pre_ans = 0
    for key,value in check.items():
        if len(value) == k:
            pre_ans += 1
    ans = max(ans,pre_ans)

print(ans)