a, b = [int(i) for i in input().split()]

x, y, z = [int(i) for i in input().split()]


a -= 2 * x + y
b -= 3 * z + y

print(max(-a, 0) + max(-b, 0))
