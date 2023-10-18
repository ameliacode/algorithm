n = int(input())
k = int(input())

new_board = [[0]*(n+1) for _ in range(n+1)]

for _ in range(k):
    x,y = map(int,input().split())
    new_board[x][y] = 1

l = int(input())
control={}
for _ in range(l):
    x,c = input().split()
    control[int(x)] = c

dx = [0,1,0,-1]
dy = [1,0,-1,0]

def turn(direction, c):
    if c == 'L':
        direction = (direction - 1) % 4
    else:
        direction = (direction + 1) % 4
    return direction

def simulate():
    time = 0
    direction = 0
    x,y = 1,1
    new_board[x][y] = 2
    snake = [(x,y)]
    while True:
        time += 1
        nx = x + dx[direction]
        ny = y + dy[direction]
        if 0 < nx <= n and 0 < ny <= n and new_board[nx][ny] != 2:
            if new_board[nx][ny] == 0:
                snake.append((nx,ny))
                new_board[nx][ny] = 2
                px,py = snake.pop(0)
                new_board[px][py] = 0
            elif new_board[nx][ny] == 1:
                snake.append((nx,ny))
                new_board[nx][ny] = 2
        else:
            break
        x, y = nx, ny
        if time in control:
            direction = turn(direction, control[time])
    return time

print(simulate())