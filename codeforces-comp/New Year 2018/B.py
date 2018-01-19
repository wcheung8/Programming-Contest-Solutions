import itertools

n, m = [int(i) for i in input().split()]
count = 0
a = []

for i in range(n):
    a.append([i for i in input()])

instr = input()
start = [0, 0]
end = [0, 0]

def follow(map):
    pos = [start[0], start[1]]
    for c in instr:
        move = map[c]
        if move == 'U':
            pos[0] -= 1
        if move == 'D':
            pos[0] += 1
        if move == 'L':
            pos[1] -= 1
        if move == 'R':
            pos[1] += 1

        if pos == end:
            return True

        if pos[0] < 0 or pos[0] >= n or pos[1] < 0 or pos[1] >= m:
            return False

        if a[pos[0]][pos[1]] == '#':
            return False

    return False


for i in range(n):
    for j in range(m):
        if a[i][j] == 'S':
            start = [i, j]
        elif a[i][j] == 'E':
            end = [i, j]


for d in itertools.permutations("UDLR"):
    map = {'0': d[0], '1': d[1], '2': d[2], '3': d[3]}
    if follow(map):
        count += 1

print(count)
