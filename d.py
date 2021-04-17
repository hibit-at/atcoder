import itertools

ss = []
for i in range(5):
    ss.append(input())

all_character = set()

for s in ss:
    for c in s:
        all_character.add(c)

size = len(all_character)

if size > 10:
    print("UNSOLVABLE")
    exit()

all_character = list(all_character)
indices = []
for s in ss:
    index = []
    for c in s:
        index.append(all_character.index(c))
    indices.append(index)

for case in itertools.permutations(range(10), size):

    isTopzero = False
    for index in indices:
        if case[index[0]] == 0:
            isTopzero = True

    if isTopzero:
        continue

    nums = []

    for index in indices:
        num = 0
        for i in index:
            num *= 10
            num += case[i]
        nums.append(num)

    num_sum = 0

    for num in nums:
        num_sum += num

    if num_sum == 2*nums[-1]:
        for num in nums:
            print(num)
        # exit()

print("UNSOLVABLE")
