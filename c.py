import numpy as np

n = int(input())

v = np.zeros((n,5))

for i in range(n):
    v[i] = list(map(int,input().split(' ')))

v = v.astype('int64')
# print(v)
vt = v.transpose()

ans = 0

for i in range(n):
    for j in range(i+1,n):
        # print(f"seaching {i},{j}")
        tmp = np.zeros(5)
        for k in range(5):
            tmp[k] = max(v[i][k],v[j][k])
        # print("tempral max is",tmp)
        where_min = np.argmin(tmp)
        how_min = np.min(tmp)
        # print("week point is ",how_min)
        where_target_vector = np.argmax(vt[where_min])
        target_vector = v[where_target_vector]
        # print("target vector is ",target_vector)
        for k in range(5):
            tmp[k] = max(tmp[k],target_vector[k])
        tmp = tmp.astype('int64')
        ans = max(ans,np.min(tmp))

print(ans)
