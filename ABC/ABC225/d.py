import sys
sys.setrecursionlimit(1000000)


class train:
    parent = None
    child = None
    num = 0

    def __init__(self, num):
        self.parent = self
        self.num = num

    def connect(self, child):
        self.child = child
        child.parent = self

    def split(self, child):
        self.child = None
        child.parent = child

    def make_children(self, ans):
        ans += [self.num]
        if self.child is not None:
            return self.child.make_children(ans)
        else:
            return ans

    def find_root(self):
        if self.parent is self:
            return self
        else:
            return self.parent.find_root()

    def __str__(self):
        return str(self.num)


n, q = map(int, input().split(' '))

trains = [train(i) for i in range(n+1)]

for _ in range(q):
    input_string = list(map(int, input().split(' ')))
    if len(input_string) == 2:
        c, x = input_string
    if len(input_string) == 3:
        c, x, y = input_string
    if c == 1:
        trains[x].connect(trains[y])
    if c == 2:
        trains[x].split(trains[y])
    if c == 3:
        root = trains[x].find_root()
        children = root.make_children([])
        children = [str(c) for c in children]
        print(len(children), ' '.join(children))
