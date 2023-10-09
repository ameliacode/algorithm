import sys

n,m = map(int, input().split())
data = []
temp = [[0]*m for _ in range(n)]

for _ in range(n):
    data.append(list(map(int, sys.stdin.readline().split())))

dx = [-1,0,1,0] #좌 상 우 하 (시계 방향)
dy = [0,1,0,-1]

result = 0

def virus(x,y): #오로지 바이러스 퍼트리는 가정 상황
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if 0 <= nx < n and 0 <= ny < m: # inside the boundary
            if temp[nx][ny] == 0:
                temp[nx][ny] = 1
                virus(nx,ny)

def get_score():
    score = 0
    for i in range(n):
        for j in range(m):
            if temp[i][j] == 0:
                score += 1
    return score

def dfs(count):
    global result
    if count == 3:
        for i in range(n):
            for j in range(m):
                temp[i][j] = data[i][j]
        for i in range(n):
            for j in range(m):
                if temp[i][j] == 2:
                    virus(i,j)
        result = max(result, get_score())
    for i in range(n):
        for j in range(m):
            if data[i][j] == 0:
                data[i][j] = 1
                count += 1
                dfs(count)
                data[i][j] = 0
                count -= 1

dfs(0)
print(result)