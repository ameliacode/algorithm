t = int(input())

for _ in range(t):
    n, m = map(int, input().split())
    array = list(map(int, input().split()))
    dp = [array[i : i + m] for i in range(0, n, m)]

    for j in range(1, m):
        for i in range(n):
            if i == 0:  # from left up
                left_up = 0
            else:
                left_up = dp[i - 1][j - 1]

            if i == n - 1:  # from left down
                left_down = 0
            else:
                left_down = dp[i + 1][j - 1]

            left = dp[i][j - 1]  # from left
            dp[i][j] = dp[i][j] + max(left_up, left_down, left)

    result = 0
    for i in range(n):
        result = max(result, dp[i][m - 1])

    print(result)
