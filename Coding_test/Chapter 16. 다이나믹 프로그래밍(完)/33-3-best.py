n = int(input())

t = []
p = []

for _ in range(n):
    x, y = map(int, input().split())
    t.append(x)
    p.append(y)

dp = [0] * (n + 1)

result = 0
for i in range(n - 1, -1, -1):
    time = t[i] + i
    if time <= n:
        dp[i] = max(dp[time] + p[i], result)
        result = dp[i]
    else:
        dp[i] = result
print(result)
