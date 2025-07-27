t = int(input())

for _ in range(t):
    n, m = map(int, input().split())
    gold = list(map(int, input().split()))
    mine = [gold[i : i + m] for i in range(0, n * m, m)]

    result = 0
    for j in range(1, m):
        for i in range(n):
            if i == 0:  # from left up
                left_up = 0
            else:
                left_up = mine[i - 1][j - 1]

            if i == n - 1:
                left_down = 0
            else:
                left_down = mine[i + 1][j - 1]

            left = mine[i][j - 1]
            mine[i][j] += max(left_up, left_down, left)

    result = max(mine[-1])
    print(result)
