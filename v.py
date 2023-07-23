n = int(input())
s = input()
st = set()
ans = 1
for c in s:
    st.add(c)
    # print(st)
    if st == set(['A', 'B', 'C']):
        print(ans)
        exit()
    ans += 1
