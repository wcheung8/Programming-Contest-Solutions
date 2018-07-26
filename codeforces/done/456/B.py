n, k = [int(i) for i in input().split()]
def f():
    for i in range(70):
        if pow(2, i) > n:
            x = i
            return x
i = f()
y = sum([pow(2, i-k-1) for k in range(i)])

if k == 1:
    print(n)
else:
    print(y)