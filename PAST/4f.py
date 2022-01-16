from collections import defaultdict
n, k = list(map(int, input().split(' ')))

df = defaultdict(int)

for i in range(n):
    s = input()
    df[s] += 1

cnt = defaultdict(int)

for d in df.items():
    cnt[d[1]] += 1

df = sorted(df.items(), key=lambda x: -x[1])

cand = df[k-1]

if cnt[cand[1]] == 1:
    print(cand[0])
else:
    print('AMBIGUOUS')
