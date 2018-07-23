import string
n, k = [int(i) for i in input().split()]
s = input()
d = {x:0 for x in string.ascii_lowercase}
for x in s:
    d[x]+=1
r = 'a'

removed = []
for c in string.ascii_lowercase:
    if k - d[c] < 0:
        r = c
        break
    removed.append(c)
    k -= d[c]

s = ''.join([l for l in s if l not in removed])

final  = []

for c in s:
    if k == 0 or c != r:
        final.append(c)
    else:
        k-=1


print(''.join(final))
