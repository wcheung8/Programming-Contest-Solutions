n = int(input().split(' ')[0])

s = input().split(' ')

flag = True
while flag:
    flag = False
    for i in range(len(s)):
        if s[i] == "undo":
            flag = True
            y = i-int(s[i+1])
            s = s[:y] + s[i+2:]
            break

p = 0
for i in range(len(s)):
    p += int(s[i])
    p %= n
    
print(p)
'''
5 4
8 -2 3 undo 2

5 10
7 -3 undo 1 4 3 -9 5 undo 2 undo 1 6

'''