from collections import defaultdict

n, m = [int(i) for i in input().split()]
x = [int(i) for i in input().split()]

h = 0
a = [0 for i in range(n)]
for i in range(1, n):
    a[i] = (x[h], x[i])
    if x[h] < x[i]:
        h = i


z = x[h]
x.pop(h)

for i in range(m):
    q = int(input()) - 1

    if q < n-1:
        print("{} {}".format(a[q + 1][0], a[q + 1][1]))
    else:
        print("{} {}".format(z, x[q % (n - 1)]))
"""
5 10
3 5 5 4 1
1
2
3
4
5
6
7
8
9
10
11
12
13

7 15
0 98 4 2 91 100 90
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
"""