from datetime import datetime
import sys

age = {}
edges = {}
roots = []

t_age = {}

def s_age(n):
    if n in t_age:
        return t_age[n]

    if n not in edges:
        t_age[n] = age[n]
        return t_age[n]

    s = age[n]

    for d in edges[n]:
        s += s_age(d)

    t_age[n] = s
    return s

c = 0
i = 0
for s in sys.stdin:
    if len(s.strip()) == 0:
        break
    if c == 0:
        c = 1
        continue
    a = s.strip().split(',')
    d1 = datetime.strptime(a[2].strip(), "%Y-%m-%d")
    d2 = datetime.strptime(a[3].strip(), "%Y-%m-%d")
    age[a[0]] = (int(abs((d2 - d1).days)/365.25))
    if a[1] is not '':
        if a[1] not in edges:
            edges[a[1]] = [a[0]]
        else:
            edges[a[1]].append(a[0])
    else:
        roots.append(a[0])
    i += 1

mage = roots[0]
print("Most Total Age Tapestry = "+ str(mage) + "," + str(s_age(mage)))

"""
name,parent_name,dob,dod
GRAYBEARD,,1872-12-10,1907-11-15
THORIN,GRAYBEARD,1903-09-29,1922-05-13
ATHENA,GRAYBEARD,1906-10-13,1926-12-20
TRITON,ATHENA,1913-10-01,1952-01-12
ALEXTHANIA,,1072-01-05,1207-07-14
GLORAX,ALEXTHANIA,1105-02-17,1317-03-21
SNEERLAX,ALEXTHANIA,1110-10-18,1298-04-16
ORGANAX,GLORAX,1229-12-01,1415-11-30
"""