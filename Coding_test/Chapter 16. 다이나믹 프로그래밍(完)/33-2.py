n = int(input())

t = []
p = []
dp = [0] * (n + 1)

for _ in range(n):
    x, y = map(int, input().split())
    t.append(x)
    p.append(y)

result = 0  # max value
for i in range(n - 1, -1, -1):
    time = t[i] + i
    if time <= n:
        dp[i] = max(p[i] + dp[time], result)
        result = dp[i]
    else:
        dp[i] = result

print(result)
