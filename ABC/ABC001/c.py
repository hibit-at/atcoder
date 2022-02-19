class Direction():

    def __init__(self, lower, upper, ans) -> None:
        self.lower = lower
        self.upper = upper
        self.ans = ans

    def __str__(self) -> str:
        return(f'{self.lower} -> {self.upper} {self.ans}')


class Speed():

    def __init__(self, lower, upper, ans) -> None:
        self.lower = lower
        self.upper = upper
        self.ans = ans

    def __str__(self) -> str:
        return(f'{self.lower} -> {self.upper} {self.ans}')


angles = [
    11.25,
    33.75,
    56.25,
    78.75,
    101.25,
    123.75,
    146.25,
    168.75,
    191.25,
    213.75,
    236.25,
    258.75,
    281.25,
    303.75,
    326.25,
    348.75,
]

names = [
    'NNE',
    'NE',
    'ENE',
    'E',
    'ESE',
    'SE',
    'SSE',
    'S',
    'SSW',
    'SW',
    'WSW',
    'W',
    'WNW',
    'NW',
    'NNW',
]

borders = [
    0,
    0.3,
    1.6,
    3.4,
    5.5,
    8.0,
    10.8,
    13.9,
    17.2,
    20.8,
    24.5,
    28.5,
    32.7,
    200.1,
]

dirs = []
size = len(angles)
for i in range(size-1):
    dirs.append(Direction(angles[i], angles[i+1], names[i]))

size = len(borders)
speeds = []
for i in range(size-1):
    speeds.append(Speed(borders[i], round(borders[i+1]-0.1, 2), i))

def solve(d, w):

    d /= 10

    base = w - (w % 6)
    left = w % 6
    base /= 60
    if left >= 3:
        base += 0.1
    base = round(base,2)

    ans_dir = ''
    for dir in dirs:
        if dir.lower <= d and d < dir.upper:
            ans_dir = dir.ans
    if ans_dir == '':
        ans_dir = 'N'

    for speed in speeds:
        if speed.lower <= base and base <= speed.upper:
            ans_wind = speed.ans

    if ans_wind == 0:
        print('C 0')
    else:
        print(ans_dir, ans_wind)

if __name__ == '__main__':
    d, w = list(map(float, input().split(' ')))
    solve(d,w)