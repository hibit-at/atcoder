from datetime import datetime, timedelta
y, m, d = list(map(int, input().split('/')))
now = datetime(y, m, d)
while 1:
    s = str(now)[:10]
    st = set()
    for c in s:
        st.add(c)
    if len(st) == 3:
        print(s.replace('-','/'))
        break
    now += timedelta(days=1)
