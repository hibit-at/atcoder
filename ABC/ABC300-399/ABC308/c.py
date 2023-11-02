class Y():
    a = 0
    b = 0

    def __init__(self, a, b) -> None:
        self.a = a
        self.b = b

    def __repr__(self) -> str:
        return f'({self.a},{self.b})'

    def __lt__(self, other):
        return self.a*other.b > other.a*self.b


n = int(input())

AB = []

for i in range(n):
    a,b = list(map(int, input().split(' ')))
    AB.append((Y(a,b),i))

AB.sort()
# print(AB)

print(*[ans[1]+1 for ans in AB])