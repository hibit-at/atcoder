from collections import deque

n, k = map(int, input().split(' '))
a = list(map(int, input().split(' ')))
q = deque()
ans = 0

kinds = 0
num_dict = {}

for i in range(n):
    now_app = a[i]
    q.append(now_app)
    if now_app not in num_dict:
        num_dict[now_app] = 1
        kinds += 1
    else:
        num_dict[now_app] += 1
    while kinds > k:
        now_rem = q.popleft()
        if now_rem in num_dict:
            if num_dict[now_rem] == 1:
                num_dict.pop(now_rem)
                kinds -= 1
            else:
                num_dict[now_rem] -= 1
    # print(q)
    # print(num_dict, kinds)
    ans = max(ans, len(q))

print(ans)
