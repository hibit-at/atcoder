from datetime import datetime,timedelta

k = int(input())

date = datetime(2022,1,1,21,00)
date += timedelta(minutes=k)

print(f'{date.hour}:{str(date.minute).zfill(2)}')