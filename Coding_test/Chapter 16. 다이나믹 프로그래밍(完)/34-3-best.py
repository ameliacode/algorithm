n = int(input())
array = list(map(int, input().split()))
array.reverse()

dp = [1] * n

for i in range(1, n):
    for j in range(i):
        if array[i] > array[j]:  # 열외
            dp[i] = max(dp[i], dp[j] + 1)

print(n - max(dp))
