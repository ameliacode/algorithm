from collections import deque

n, k = map(int, input().split())

lab = []
virus = []
for x in range(n):
    row = list(map(int, input().split()))
    lab.append(row)
    for y in range(n):
        if row[y] != 0:
            virus.append([row[y], 0, x, y])
virus.sort()
target_s, target_x, target_y = map(int, input().split())

dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]

queue = deque(virus)
while True:
    v, s, x, y = queue.popleft()
    if s == target_s:
        break
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if 0 <= nx < n and 0 <= ny < n and lab[nx][ny] == 0:
            lab[nx][ny] = s
            queue.append([v, s + 1, nx, ny])

print(lab[target_x - 1][target_y - 1])
