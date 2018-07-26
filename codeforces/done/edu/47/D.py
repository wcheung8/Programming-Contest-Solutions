
n, m = [int(i) for i in input().split()]
s = input().split()

thresh = n/m

d = {x:0 for x in range(m)}

bad = []

ma = 0
for n in s:
    i= int(n) % m
    d[i] += 1

for i in range(m):
    if d[i] > thresh:
        bad.append(i)
