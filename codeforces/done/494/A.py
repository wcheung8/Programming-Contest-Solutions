
input()

x = [int(i) for i in input().split()]

y = [x.count(i) for i in x]

print(max(y))