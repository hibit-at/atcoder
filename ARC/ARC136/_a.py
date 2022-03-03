n = int(input())
s = input()
t = s.split('C')

def solve(substring):
    substring = substring.replace('BB','A')
    substring = ''.join(sorted(substring))
    return substring

print('C'.join(map(solve,t)))