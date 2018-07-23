n, k = [int(i) for i in input().split()]
p = [(int(v), i) for i, v in enumerate(input().split())]

p = sorted(p, key=lambda student: -student[0])
a = []
for i in range(k):
    a.append(p[i])
a.append((0, n))
a = sorted(a, key=lambda student: student[1])

print(sum([pair[0] for pair in a]))

x = []
start = 0
for i in range(k - 1):
    x.append(str(a[i][1] - start + 1))
    start = a[i][1] + 1
x.append(str(n -start))
print(" ".join(x))