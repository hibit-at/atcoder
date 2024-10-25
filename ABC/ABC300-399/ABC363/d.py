n = int(input())

def digit_max(d):
    if d == 1:
        return 10
    else:
        n = (d+1)//2
        ans = 1
        for i in range(n):
            if i == 0:
                ans *= 9
            else:
                ans *= 10
    return ans

for i in range(1,100):
    print(digit_max(i))