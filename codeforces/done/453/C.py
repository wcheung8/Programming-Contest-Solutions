n = int(input())

h = [int(i) for i in input().split()]

flag = 0
for i in range(n):
    if h[i] >= 2 and h[i+1] >= 2:
        flag = i

if flag:
    a = []
    c = 0
    for i in range(n+1):
        for j in range(h[i]):
            a.append(c)
        c += h[i]
            
        
    b = []
    c = 0
    for i in range(n+1):
        for j in range(h[i]):
            if i == flag+1 and j == 0:
                b.append(c-1)
            else:
                b.append(c)
        c += h[i]
            
        
    print("ambiguous")
    print(" ".join([str(i) for i in a]))
    print(" ".join([str(i) for i in b]))

else:
    print("perfect")