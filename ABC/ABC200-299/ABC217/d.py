
class tree:

    isParent = True
    length = 0
    split_pos = 0
    childL = None
    childR = None

    def __init__(self, l):
        self.length = l

    def split(self, x):
        if self.isParent:
            self.childL = tree(x)
            self.childR = tree(self.length-x)
            self.isParent = False
            self.split_pos = x
        else:
            if x < self.split_pos:
                self.childL.split(x)
            else:
                self.childR.split(x-self.split_pos)

    def getLen(self, x):
        if self.isParent:
            return self.length
        else:
            if x < self.split_pos:
                return self.childL.getLen(x)
            else:
                return self.childR.getLen(x-self.split_pos)


l, q = map(int, input().split())

t = tree(l)


for _ in range(q):
    c, x = map(int, input().split())
    if c == 1:
        t.split(x)
    else:
        print(t.getLen(x))
