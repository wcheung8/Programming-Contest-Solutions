from collections import defaultdict

n = int(input())
x = []
x.append([int(i) for i in input().split()])
x.append([int(i) for i in input().split()])


# dp[i][j] = max height team picking up to column i, with choice row j

dp = [[0 for _ in range(n)] for _ in range(2)]

dp[0][0] = x[0][0]
dp[1][0] = x[1][0]

for j in range(1, n):
    for i in range(2):
        dp[i][j] = max(dp[1-i][j-1] + x[i][j], dp[i][j-1])

print(max(dp[0][-1], dp[1][-1]))