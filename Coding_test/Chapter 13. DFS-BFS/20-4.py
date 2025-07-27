from copy import deepcopy
from itertools import combinations

n = int(input())

hall = []
teachers = []
vacent = []

for i in range(n):
    row = list(input().split())
    for j in range(n):
        if row[j] == "X":
            vacent.append((i, j))
        if row[j] == "T":
            teachers.append((i, j))
    hall.append(row)


def watch(x, y, i, hall):
    if i == 0:  # up
        while x >= 0:
            if hall[x][y] == "S":
                return True
            elif hall[x][y] == "O":
                return False
            x -= 1
    if i == 1:  # down
        while x < n:
            if hall[x][y] == "S":
                return True
            elif hall[x][y] == "O":
                return False
            x += 1
    if i == 2:  # left
        while y >= 0:
            if hall[x][y] == "S":
                return True
            elif hall[x][y] == "O":
                return False
            y -= 1
    if i == 3:  # right
        while y < n:
            if hall[x][y] == "S":
                return True
            elif hall[x][y] == "O":
                return False
            y += 1


def process(hall):
    for x, y in teachers:
        for i in range(4):
            if watch(x, y, i, hall):
                return False
    return True  # checkmate


result = False
for candidates in list(combinations(vacent, 3)):
    new_hall = deepcopy(hall)
    for x, y in candidates:
        new_hall[x][y] = "O"
    if process(new_hall):
        result = True
        break

if result:
    print("YES")
else:
    print("NO")
