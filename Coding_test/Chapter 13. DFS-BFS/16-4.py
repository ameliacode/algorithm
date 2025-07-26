from copy import deepcopy
from itertools import combinations

n, m = map(int, input().spit())

lab = []
virus = []
vacent = []

for x in range(n):
    row = list(map(int, input().split()))
    for y in range(m):
        if row[y] == 2:
            virus.append((x, y))


def check(lab):
    count = 0
    for x in range(n):
        for y in range(m):
            if lab[x][y] == 0:
                count += 1
    return count


dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]


def simulate(lab, x, y):
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if lab[nx][ny] == 0:
            lab[nx][ny] = 2
            simulate(lab, nx, ny)


candidates = list(combinations(vacent, 3))

answer = 0
for walls in candidates:
    new_lab = deepcopy(lab)
    for x, y in walls:
        new_lab[x][y] = 1
    for x, y in virus:
        simulate(new_lab, x, y)
    answer = max(answer, check(new_lab))

print(answer)
