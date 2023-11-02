ok = 0
ng = 10000000

while abs(ng-ok)>1:
    mid = ng+ok
    mid //= 2
    if len(str(mid*mid)) > 13:
        ng = mid
    else:
        ok = mid

print(ok*ok)