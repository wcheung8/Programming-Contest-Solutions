from datetime import datetime
import sys

people = {}
age = {}
roots = []

def get_max(p):
    if p in age:
        return age[p]
    if len(p) == 0:
        return 0
    a = people[p][1] + get_max(people[p][0])
    age[p] = a
    return a

def path(p):
    r = p
    a = people[p][0]
    while len(a) != 0:
        r = a + ' -> ' + r
        a = people[a][0]
    return r

c = 0
for s in sys.stdin:
    if c == 0:
        c = 1
        continue
    a = s.strip().split(',')
    d1 = datetime.strptime(a[2], "%Y-%m-%d")
    d2 = datetime.strptime(a[3], "%Y-%m-%d")
    people[a[0]] = (a[1], abs((d2 - d1).days))
    m = a[0]

for p in people:
    get_max(p)

for a in age:
    if age[a] > age[m]:
        m = a

print(path(m))
"""
name,parent_name,dob,dod
GRAYBEARD,,1872-12-10,1907-11-15
THORIN,GRAYBEARD,1903-09-29,1922-05-13
ATHENA,GRAYBEARD,1906-10-13,1926-12-20
TRITON,ATHENA,1913-10-01,1952-01-12
"""