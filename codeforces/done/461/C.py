n, k = [int(i) for i in input().split()]

if k > 100:
    print("No")
else:
    x = set()
    for i in range(1, k+1):
        x.add(n % i)

    if(len(x) != k):
        print("No")
    else:
        print("Yes")
