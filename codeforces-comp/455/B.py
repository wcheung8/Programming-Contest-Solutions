n = int(input())
s = 0
for i in range(1,n+1):
    if i <= n//2:
        s += i
    else:
        s += n - i + 1


print(s)