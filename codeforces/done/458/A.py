import math
def is_square(n):
    if n<0:
        return False
    return math.sqrt(n).is_integer()
n = int(input())
a = [int(i) for i in input().split()]

m = max([i for i in a if not is_square(i)])

print(m)