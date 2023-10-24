from collections import deque

n,l,r = map(int, input().split())
a = []

for _ in range(n):
    a.append(list(map(int, input().split())))

dx = [-1,0,1,0]
dy = [0,-1,0,1]

def check_union(x,y,index,union):
    united = []
    united.append((x,y))

    q = deque(united)
    q.append((x,y))
    union[x][y] = index
    summary=a[x][y]
    count = 1
    while q:
        x,y = q.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < n and 0 <= ny < n and union[nx][ny] == -1:
                if l <= abs(a[nx][ny] - a[x][y]) <= r:
                    q.append((nx,ny))
                    union[nx][ny] = index
                    summary += a[nx][ny]
                    count += 1
                    united.append((nx,ny))
    
    for x,y in united:
        a[x][y] = summary // count
        
    return count

total_count = 0
while True:
    union = [[-1]*n for _ in range(n)]
    index = 0
    for i in range(n):
        for j in range(n):
            if union[i][j] == -1:
                check_union(i,j,index,union)
                index += 1
    if index == n*n:
        break
    total_count += 1
print(total_count)