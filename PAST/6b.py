s = input()
if s.find('post') == -1:
    print('none')
else:
    print(s.find('post')//4+1)