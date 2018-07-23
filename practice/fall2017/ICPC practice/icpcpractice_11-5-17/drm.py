s = input()

a = [x for x in s[:len(s)//2]]
b = [x for x in s[len(s)//2:]]
n = len(a)
x = 0
y = 0
for i in range(n):
    x += ord(a[i]) - 65 
    y += ord(b[i]) - 65
    
for i in range(n):
    a[i] = chr( ((ord(a[i]) + x - 65)%26) + 65)
    b[i] = chr( ((ord(b[i]) + y - 65)%26) + 65)

m = ''
for i in range(n):
    m += chr( ((ord(a[i]) + ord(b[i]) - 130)%26) + 65)
    
    
print(m)