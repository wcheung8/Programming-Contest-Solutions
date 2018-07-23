n,k = [int(i) for i in input().split()]
x = [int(i) for i in input().split()]

s = [(i) for i, v in enumerate(x) if v > k]

if len(s) == 0:
    print(len(x))
else:
    print(len(x)-(s[-1]-s[0]+1))