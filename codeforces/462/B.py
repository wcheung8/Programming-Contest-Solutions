k = int(input())
if k > 36:
    print(-1)
else:
    x = ""
    for i in range(k//2):
        x += '8'
    if k % 2:
        x += '6'

    print(x)
