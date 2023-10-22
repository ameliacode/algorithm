from collections import deque

n,k = map(int, input().split())

lab = []
start = []
for i in range(n):
    lab.append(list(map(int,input().split())))
    for j in range(n):
        if lab[i][j] != 0:
            start.append([lab[i][j],0,i,j])

start.sort()
target_s,target_x,target_y = map(int,input().split())

dx = [-1,0,1,0]
dy = [0,-1,0,1]
q = deque(start)

while q:
    virus,s,x,y = q.popleft()
    if s == target_s:
        break
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if 0<=nx<n and 0<=ny<n and lab[nx][ny] == 0:
            lab[nx][ny] = virus
            q.append((virus, s+1, nx, ny))

print(lab[target_x-1][target_y-1])