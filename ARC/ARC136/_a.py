n = int(input())
s = input()
t = s.split('C')

def solve(substring):
    A_count = substring.count('A')
    B_count = substring.count('B')
    if B_count % 2 == 0:
        substring = 'A' * (A_count + B_count // 2)
    else:
        substring = 'A' * (A_count + B_count // 2) + 'B'
    return substring

print('C'.join(map(solve, t)))
