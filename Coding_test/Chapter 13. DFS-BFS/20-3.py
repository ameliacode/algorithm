from itertools import combinations
from copy import deepcopy

n = int(input())

hall = []
teachers = []
candidates = []

for i in range(n):
    hall.append(list(map(int, input().split())))
    for j in range(n):
        if hall[i][j] == 'X':
            candidates.append((i,j))
        if hall[i][j] == 'T':
            teachers.append((i,j))

def watch(x,y,i,temp): # i as direction
    if i == 0: #상
        while x >= 0:
            if temp[x][y] == 'S':
                return True
            elif temp[x][y] == 'O':
                return False
            x -= 1
    if i == 1: #하
        while x < n:
            if temp[x][y] == 'S':
                return True
            elif temp[x][y] == 'O':
                return False
            x += 1
    if i == 2: #좌
        while y >= 0:
            if temp[x][y] == 'S':
                return True
            elif temp[x][y] == 'O':
                return False
            y -= 1
    if i == 3: #우
        while y < n:
            if temp[x][y] == 'S':
                return True
            elif temp[x][y] == 'O':
                return False
            y += 1


def process(hall):
    for x,y in teachers:
        for i in range(4):
            if watch(x,y,i,hall):
                return True
    return False


result = False
for candidate in list(combinations(candidates, 3)):
    temp = deepcopy(hall)
    for c in list(candidate):
        temp[c[0]][c[1]] = 'O'
    if not process(temp):
        result = True
        break

if result:
    print("YES")
else:
    print("NO")


