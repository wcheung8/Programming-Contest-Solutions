a = [i for i in input()]
n = a.count('1')
b = [i for i in a if i != '1']

if '2' in b:
    x = b.index('2')
    print(''.join(b[:x]) + n * '1' + ''.join(b[x:]))
else:
    print(''.join(b) + n * '1')
