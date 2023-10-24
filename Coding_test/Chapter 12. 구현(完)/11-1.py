N = int(input())
M = int(input())

data = [[0] * (N+1) for _ in range(N+1)]
for _ in range(M):
    x, y = map(int, input().split())
    data[x][y] = 1

info= []
L = int(input())
for _ in range(L):
    X, C = input().split()
    info.append([int(X), C])

dx = [0, 1, 0, -1] # 문제 해결 point
dy = [1, 0, -1, 0]

def turn(direction, C):
    if C == "L":
        direction = (direction - 1) % 4
    else:
        direction = (direction + 1) % 4
    return direction

def simulate():
    x,y = 1,1
    data[x][y] = 2
    direction = 0
    time = 0
    index = 0 # 다음 회전 정보
    q = [(x,y)] #뱀이 차지하고 있는 정보
    while True:
        nx = x + dx[direction]
        ny = y + dy[direction]

        if 1 <= nx <= N and 1 <= ny <= N and data[nx][ny] != 2:
            if data[nx][ny] == 0: #사과가 없으면 꼬리 제거
                data[nx][ny] = 2
                q.append((nx,ny))
                px, py = q.pop(0)
                data[px][py] = 0
            if data[nx][ny] == 1: #사과가 있으면 꼬리 그대로
                data[nx][ny] = 2
                q.append((nx,ny))
        else:
            time += 1
            break
        x, y = nx, ny
        time += 1
        if index < 1 and time == info[index][0]: #회전할 시간인 경우
            direction = turn(direction, info[index][1])
            index += 1
    return time 

print(simulate())

