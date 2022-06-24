from itertools import product
for state in product('abc',repeat=int(input())):
    print(''.join(state))