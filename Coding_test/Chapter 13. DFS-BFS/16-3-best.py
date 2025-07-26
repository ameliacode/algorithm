from copy import deepcopy
from itertools import combinations

n, m = map(int, input().split())

lab = []
virus = []
vacent = []
for i in range(n):
    lab.append(list(map(int, input().split())))
    for j in range(m):
        if lab[i][j] == 0:
            vacent.append([i, j])
        if lab[i][j] == 2:
            virus.append([i, j])

candidate = list(combinations(vacent, 3))

dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]


def check(lab):
    count = 0
    for i in range(n):
        for j in range(m):
            if lab[i][j] == 0:
                count += 1
    return count


def simulate(lab, x, y):
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if 0 <= nx < n and 0 <= ny < m:
            if lab[nx][ny] == 0:
                lab[nx][ny] = 2
                simulate(lab, nx, ny)
    return lab


answer = 0
for walls in candidate:
    new_lab = deepcopy(lab)
    for wall in list(walls):
        new_lab[wall[0]][wall[1]] = 1
    for v in virus:
        new_lab = simulate(new_lab, v[0], v[1])
    answer = max(answer, check(new_lab))

print(answer)
