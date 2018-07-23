input()

x = [int(i) for i in input().split()]

s = sorted(x)
avail = 0

m = s[0]
curr = m
tmp = 0
count = 0

for j in range(len(s)):
    i = s[j]
    if i == m:
        avail += 1
    else:

        if curr != i:
            avail += tmp
            tmp = 0

        if avail > 0:
            avail -= 1
            count += 1

        curr = i
        tmp += 1

print(count)
