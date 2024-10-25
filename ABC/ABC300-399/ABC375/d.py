def count_palindromic_triplets(S):
    from collections import defaultdict

    char_positions = defaultdict(list)
    for idx, char in enumerate(S):
        char_positions[char].append(idx + 1)  # positions are 1-indexed

    total = 0
    for positions in char_positions.values():
        m = len(positions)
        pre_sum = [0] * (m + 1)
        for i in range(1, m + 1):
            pre_sum[i] = pre_sum[i - 1] + positions[i - 1]
        total_c = 0
        for i in range(1, m):
            total_c += (pre_sum[m] - pre_sum[i]) - (m - i) * positions[i - 1] - (m - i)
        total += total_c

    return total

s = input()
print(count_palindromic_triplets(s))