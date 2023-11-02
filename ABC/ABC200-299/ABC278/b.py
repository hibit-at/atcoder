from datetime import datetime,timedelta

h,m = list(map(int, input().split(' ')))

def check(date : datetime):
    h = date.hour
    m = date.minute
    head = h // 10
    m_head = m // 10
    if head == 2 and m_head >= 4:
        return False
    d = h % 10
    return d <= 5

now = datetime(2020,1,1,h,m)

while(not check(now)):
    now += timedelta(minutes=1)

print(f'{now.hour} {now.minute}')