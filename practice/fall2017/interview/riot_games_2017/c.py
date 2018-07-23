from datetime import datetime
import sys

age = {}
edges = {}
roots = []

t_age = {}
gen = {}
mem = {}

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

def s_gen(n):
    if n in gen:
        return gen[n]

    if n not in edges:
        gen[n] = 1
        return 1

    s = 1

    for d in edges[n]:
        s = max(s, s_gen(d))

    gen[n] = s+1
    return s+1

def s_mem(n):
    if n in mem:
        return mem[n]

    if n not in edges:
        mem[n] = 1
        return mem[n]

    s = 1

    for d in edges[n]:
        s += s_mem(d)

    mem[n] = s
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
mmem = roots[0]
mgen = roots[0]
for r in roots:
    mage = mage if s_age(mage) >= s_age(r) else r
    mmem = mmem if s_mem(mmem) >= s_mem(r) else r
    mgen = mgen if s_gen(mgen) >= s_gen(r) else r

print("Most Members Tapestry = " + str(mmem) + "," + str(s_mem(mmem)))
print("Most Total Age Tapestry = "+ str(mage) + "," + str(s_age(mage)))
print("Most Generations Tapestry = "+ str(mgen) + "," + str(s_gen(mgen)))


"""
name,parent_name,dob,dod
GRAYBEARD,,1272-12-10,1407-11-15
THORIN,GRAYBEARD,1303-09-29,1922-05-13
ATHENA,GRAYBEARD,1506-10-13,1926-12-20
TRITON,ATHENA,1913-10-01,2352-01-12
ALEXTHANIA,,1072-01-05,1207-07-14
GLORAX,ALEXTHANIA,1105-02-17,1317-03-21
ORGANAX,GLORAX,1229-12-19,1415-11-30
MEGULUS,GLORAX,1270-10-09,1409-12-21
TRANTAZ,GLORAX,1255-07-01,1425-08-17
SNEERLAX,ALEXTHANIA,1110-07-16, 1376-05-10
ORANIA,ALEXTHANIA,1109-10-18, 1298-04-16
TARIN,,1200-02-12,1307-01-14
TERRA,TARIN,1225-09-18,1410-07-22
GEON,TERRA,1390-07-25, 1451-08-11
MAXIMUS,GEON,1440-05-24,1517-12-03
DOREN,MAXIMUS,1485-03-14,1587-01-11
YARIS,DOREN,1543-04-07,1610-03-27
"""