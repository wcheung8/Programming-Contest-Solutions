a = input()
b = input()

l = min(len(a), len(b))
m = 0
for i in range(1,l+1):
    if(a[-i] == b[-i]):
        m = i
    else:
        break

print(len(a) - m + len(b) - m)
