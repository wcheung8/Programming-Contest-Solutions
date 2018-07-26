n = int(input())
x  = []
def search(s, t):
    if len(s) == 0:
        return True
    x = int(s[0])
    for i in t:
        if x in i:
            if search(s[1:], [n for n in t if n != i]):
                return True
    return False



for i in range(n):
    s = input()
    a = []
    for i in s.split(" "):
        a.append(int(i))
    x.append(tuple(a))

m = 0
for i in range(10000):
    ss = i+1
    s = str(ss)
    if search(s, x):
        m = ss
    else:
        break

print(m)
