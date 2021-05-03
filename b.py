import numpy as np

m, k = map(int, input().split())
n = k*(m-1)+1

# 問題文の操作を簡潔に記述する行列b_matrixを定義
# 問題文の操作は「『対角成分の頭にベクトルBを持つ行列』を単位行列にk回乗算することに等しい
# 単位行列へのk乗は、つまり自身のk乗に等しい
b_matrix = np.eye(n).astype('int64')  # デフォルトだとfloatなので注意
b_vector = list(map(int, input().split()))
b_vector = np.array(b_vector)

# 「対角成分の頭にベクトルBを持つ行列」ような行列を定義
for i in range(n-m+1):
    b_matrix[i][i:i+m] = b_vector

# k乗後の1列目が即ち求める答えである
ans_matrix = np.linalg.matrix_power(b_matrix, k)
ans = []
for i in range(n):
    ans.append(ans_matrix[0][i])
ans = map(str, ans)
print(' '.join(ans))
