n, m = [int(i) for i in input().split()]

asdf = 0

for i in range(n):
    a, b = [int(i) for i in input().split()]
    if a <= asdf:
        asdf = max(b, asdf)
    
if m <= asdf:
    print("YES")
else:
    print("NO")
