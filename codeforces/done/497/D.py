import sys

n = int(input())

print(1, 1)
sys.stdout.flush()

r1 = 1
r2 = 1
l1 = 1
l2 = 1
last = 0

q = int(input())
l = 0
while q != 0 and l < 600:
    l += 1

    if q == 1:
        l1 += r1
        r1 *= 2
        last = 1

        if l1 > n:
            r1 = (n - (l1 - r1 // 2)) * 2
            l1 = n

    if q == 2:
        l2 += r2
        r2 *= 2
        last = 2

        if l2 > n:
            r2 = (n - (l2 - r2 // 2)) * 2
            l2 = n
    if q == 3:

        if last == 1:
            l1 -= r1 // 2
            r1 = 1
        else:
            l2 -= r2 // 2
            r2 = 1

    print(l1, l2)
    sys.stdout.flush()

    q = int(input())
