from itertools import combinations
import copy

n,m = map(int, input().split())
data = []
walls = []
virus = []

for i in range(n):
    data.append(list(map(int, input().split())))
    for j in range(m):
        if data[i][j] == 0:
            walls.append((i,j))
        if data[i][j] == 2:
            virus.append((i,j))

dx = [-1,0,1,0]
dy = [0,1,0,-1]

candidates = list(combinations(walls, 3))

def simulate(temp, x,y):
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if 0 <= nx < n and 0 <= ny < m:
            if temp[nx][ny] == 0:
                temp[nx][ny] = 2
                simulate(temp, nx, ny)
    return temp

def count(temp):
    total = 0
    for i in range(n):
        for j in range(m):
            if temp[i][j] == 0:
                total += 1
    return total

max_value = 0
for candidate in candidates:
    temp = copy.deepcopy(data)
    for c in list(candidate):
        temp[c[0]][c[1]] = 1
    for v in virus:
        result = simulate(temp, v[0],v[1])
    
    max_value = max(count(result), max_value)

print(max_value)