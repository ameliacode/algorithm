n = int(input())

dp = []

for i in range(n):
    array = list(map(int, input().split()))
    dp.append(array)


for i in range(1, n):
    for j in range(i + 1):
        if j == 0:
            up_left = 0
            up_right = dp[i - 1][j]
        elif j == i:
            up_left = dp[i - 1][j - 1]
            up_right = 0
        else:
            up_left = dp[i - 1][j - 1]
            up_right = dp[i - 1][j]

        dp[i][j] = dp[i][j] + max(up_left, up_right)

result = max(dp[n - 1])

print(result)
