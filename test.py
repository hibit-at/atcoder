import re

# pattern = re.compile('*b*')

target = 'aabcc'

after = re.sub('.b.','***',target)

print(after)