p = list(input().split(' '))

alpha = 'abcdefghijklmnopqrstuvwxyz'

p = [alpha[int(pp)-1] for pp in p]

print(''.join(p))