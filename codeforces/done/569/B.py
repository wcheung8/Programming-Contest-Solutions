from collections import defaultdict

n = int(input())
x = [int(i) for i in input().split()]

mm = 0
s = 1
for i in range(len(x)):
    if x[i] >= 0:
        x[i] = -x[i] - 1
        s *= -1

    if x[i] < x[mm]:
        mm = i


if n % 2 == 1:
    x[mm] = -x[mm] - 1

print(*x)
