t = int(input())

for _ in range(t):
    n, m = map(int, input().split())
    array = list(map(int, input().split()))
    gold = [array[i : i + m] for i in range(0, len(array), m)]

    for x in range(1, m):
        for y in range(n):
            if y == 0:
                left_up = 0
            else:
                left_up = gold[y - 1][x - 1]
            if y == n - 1:
                left_down = 0
            else:
                left_down = gold[y + 1][x - 1]
            left = gold[y][x - 1]
            gold[y][x] += max(left_down, left_up, left)

    print(max([gold[i][-1] for i in range(n)]))
