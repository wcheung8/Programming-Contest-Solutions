n, q = [int(i) for i in input().split()]
superior = [0] + [int(i) - 1 for i in input().split()]
dp = [[i] for i in range(n)]
list = [[] for i in range(n)]
done = [False for i in range(n)]
children = [0 for i in range(n)]

que = []


def get(n):
    if done[n]:
        return dp[n]

    for i in list[n]:
        dp[n] += get(i)

    done[n] = True

    if n == 0:
        return dp[n]
    children[superior[n]] -= 1
    if children[superior[n]] == 0:
        que.append(superior[n])

    return dp[n]


for i in range(1, n):
    list[superior[i]].append(i)
    children[superior[i]] += 1
for i in range(n):
    if len(list[i]) == 0:
        que.append(i)

children[0] -= 1

while len(que) > 0:
    get(que.pop())

queries = []

for i in range(q):
    index, k = [int(i) - 1 for i in input().split()]
    if k >= len(dp[index]):
        print(-1)
    else:
        print(dp[index][k] + 1)
