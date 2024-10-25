n,limit_of_sum_dist = list(map(int, input().split(' ')))
focal_points = [list(map(int, input().split(' '))) for i in range(n)]
valid_lattice = []
for x in range(-100,100):
    for y in range(-100,100):
        dist = 0
        for fx,fy in focal_points:
            dist += abs(x-fx) + abs(y-fy)
        # print(dist)
        if dist <= limit_of_sum_dist:
            print(dist)
            valid_lattice.append((x,y))
print(valid_lattice)

import matplotlib.pyplot as plt

# valid_lattice に格納されている点をプロット
x_values = [x for x, y in valid_lattice]
y_values = [y for x, y in valid_lattice]

plt.figure(figsize=(8, 8))
plt.scatter(x_values, y_values, c='blue', marker='o', s=10)

# グリッド線を追加
plt.grid(True)

# 軸ラベル
plt.xlabel('X')
plt.ylabel('Y')

# タイトル
plt.title('Valid Lattice Points')

# プロットの表示
# plt.show()


for i in range(-10,10):
    d = 0
    for x,y in focal_points:
        d += abs(y-i)
    print(f'{i=} {d=}')