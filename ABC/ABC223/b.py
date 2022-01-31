s = input()
n = len(s)
s = s*2

sorts = []

for i in range(n):
    sorts.append(s[i:i+n])

sorts.sort()

print(sorts[0])
print(sorts[-1])