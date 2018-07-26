a, b, x = [int(i) for i in input().split()]

s = ""

for i in range(x + 1):
    if a > b:

        if i % 2 == 0:
            s += '0'
        else:
            s += '1'
    else:
        if i % 2 == 1:
            s += '0'
        else:
            s += '1'

s = s.replace('0', '0' * (a - s.count('0') + 1), 1)
s = s.replace('1', '1' * (b - s.count('1') + 1), 1)

print(s)
