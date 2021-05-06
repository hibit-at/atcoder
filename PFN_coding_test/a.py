s = input()

# 桁が大きい程重要なので、先頭からgreedyに最小値を選んでいけばよい
# ただ、残りの数字を確保する必要があるので、探索する範囲に注意

# 先頭の文字topを決定
# 4個目までの最小値を先頭にすればそれが最適
s_search = sorted(s[:4])
top = s_search[0]
top_pos = 0
for i in range(4):
    if s[i] == top:
        top_pos = i
        break

# 2つ目の文字secondを決定
# 先頭の文字「の次」から、元の文字列で5番目までの最小値が最適
s_search = sorted(s[top_pos+1:5])
second = s_search[0]
second_pos = top_pos+1
for i in range(top_pos+1, 5):
    if s[i] == second:
        second_pos = i
        break

# 3つ目の文字thirdを決定
# 2番目の文字「の次」から、元の文字列で6番目までの最小値が最適
s_search = sorted(s[second_pos+1:6])
third = s_search[0]

ans = top + second + third

# 文字列を16進数に変換
print(int(ans, 16))
