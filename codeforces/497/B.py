n = int(input())
a = []

for i in range(n):
    a.append([int(j) for j in input().split()])
bad = 0
prev = max(a[0][0], a[0][1])
for i in range(1, len(a)):

    t = a[i]

    if prev < t[0] and prev < t[1]:
        bad = 1
        break

    if t[0] > t[1]:
        if t[0] <= prev:
            prev = t[0]
        else:
            prev = t[1]
    else:

        if t[1] <= prev:
            prev = t[1]
        else:
            prev = t[0]

if bad:
    print("NO")
else:
    print("YES")
