from collections import defaultdict
import sys

m, n = [int(i) for i in input().split()]

c = [0 for i in range(n)]

for i in range(n):
    print(1)
    sys.stdout.flush()

    c[i] = int(input())
    if c[i] == 0:
        exit(0)

l = 1
r = m

for i in range(30):
    mid = (r + l) // 2;

    print(mid)
    sys.stdout.flush()

    ans = int(input())

    if (ans * c[i % n]) == -1:
        r = mid - 1
    elif (ans * c[i % n]) == 1:
        l = mid + 1
    else:
        exit(0)
