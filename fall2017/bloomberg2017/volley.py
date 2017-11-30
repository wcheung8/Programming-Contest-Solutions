import queue

n = int(input())
set = input()
a = [set]
for i in input().split(" ")[::-1]:
    a.append(i)
a.pop()

s = input().split(" ")[::-1]
s = s[:-1]


for i in range(n):
    if(str(set) == str(a[-1])):
        x = [set]
        for j in a[0:-1]:
            x.append(j)
        a = x
    else:
        x = [s[-1]]
        for j in a[0:-1]:
            x.append(j)
        y = [a[-1]]
        for j in s[0:-1]:
            y.append(j)

        a = x
        s = y
    print(a)
    print(s)

a = a[::-1]
s = a[-1]
for i in a[:-1]:
    s += " " + i


print(s)

'''
3
A
A B C D E F
4 G H I J

6
A
A B C D E F
4 G H I J
'''