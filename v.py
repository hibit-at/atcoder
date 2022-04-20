n = int(input())
s = input()
t = s.split('C')

def solve(s: str):
    value = s.count('B') + s.count('A')*2
    return 'A' * (value//2) + 'B' * (value % 2)

print('C'.join(map(solve,t)))