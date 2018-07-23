n, m = [int(i) for i in input().split()]

a = [int(i) for i in input().split()]
b = [int(i) for i in input().split()]

if max(a) * max(b) > min(a)* min(b):
    a.remove((max(a)))
else:
    a.remove((min(a)))


print(max(max(a) * max(b), min(a)* min(b)))