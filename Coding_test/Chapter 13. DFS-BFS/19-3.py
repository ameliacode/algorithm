n = int(input())

a = list(map(int, input().split()))
add, sub, mul, div = map(int, input().split())

min_value = 1e9
max_value = -1e9


def dfs(i, now):
    global add, sub, mul, div, min_value, max_value
    if i == n:
        min_value = min(min_value, now)
        max_value = max(max_value, now)
    if add > 0:
        add -= 1
        dfs(i + 1, now + a[i])
        add += 1
    if sub > 0:
        sub -= 1
        dfs(i + 1, now - a[i])
        sub += 1
    if mul > 0:
        mul -= 1
        dfs(i + 1, now * a[i])
        mul += 1
    if div > 0:
        div -= 1
        dfs(i + 1, int(now / a[i]))
        div += 1


dfs(1, a[0])

print(max_value)
print(min_value)
