import sys
import queue
data = sys.stdin.read().splitlines()

d = data[0]
s = set()
s.add(d)

h = {}
m = {}
for l in data[1:]:
    a = l.split(" ")
    m[a[0]] = (a[2:])


def build(l):

    global h
    if l in h:
        return h[l]

    s.add(l)
    a = -1
    for i in m[l]:
        a = max(a, build(i))

    h[l] = a

    return a

build(d)

q = queue.PriorityQueue()
for i in s:
    q.put((h[i], i))

while not q.empty():
    print(q.get()[1])