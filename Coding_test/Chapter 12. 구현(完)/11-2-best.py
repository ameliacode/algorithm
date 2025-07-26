n = int(input())
k = int(input())

data = [[0] * (n + 1) for _ in range(n + 1)]

for _ in range(k):
    x, y = map(int, input().split())
    data[x][y] = 1

l = int(input())
control = {}
for _ in range(l):
    x, c = input().split()
    x = int(x)
    control[x] = c

dx = [0, 1, 0, -1]  # 행: 하, 상
dy = [1, 0, -1, 0]  # 열: 우, 좌


def turn(direction, C):
    if C == "L":
        direction = (direction - 1) % 4
    else:
        direction = (direction + 1) % 4
    return direction


def simulate():
    x, y = 1, 1
    data[x][y] = 2  # snake trace
    direction = 0
    time = 0
    snake = [(x, y)]
    while True:
        time += 1
        nx = x + dx[direction]
        ny = y + dy[direction]
        if 1 <= nx <= n and 1 <= ny <= n and data[nx][ny] != 2:
            if data[nx][ny] == 0:  # no apple
                data[nx][ny] = 2
                snake.append((nx, ny))
                px, py = snake.pop(0)
                data[px][py] = 0
            elif data[nx][ny] == 1:
                data[nx][ny] = 2
                snake.append((nx, ny))
        else:
            break
        x, y = nx, ny
        if time in control:
            direction = turn(direction, control[time])
    return time


print(simulate())
