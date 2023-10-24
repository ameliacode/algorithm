from itertools import combinations
import copy

n = int(input())
hall = []
teachers = []
candidates = []
for i in range(n):
    hall.append(list(input().split()))
    for j in range(n):
        if hall[i][j] == 'X':
            candidates.append((i,j))
        if hall[i][j] == "T":
            teachers.append((i,j))

def watch(direction,x,y,temp): # up down left right
    if direction == 0:
        while x >= 0:
            if temp[x][y] == 'S':
                return True
            elif temp[x][y] == "O":
                return False
            x -= 1
    if direction == 1:
        while x < n:
            if temp[x][y] == 'S':
                return True
            elif temp[x][y] == "O":
                return False
            x += 1
    if direction == 2:
        while y >= 0:
            if temp[x][y] == 'S':
                return True
            elif temp[x][y] == "O":
                return False
            y -= 1
    if direction == 3:
         while y < n:
            if temp[x][y] == 'S':
                return True
            elif temp[x][y] == "O":
                return False
            y += 1

def process(temp):
    for x,y in teachers:
        for i in range(4):
            if watch(i,x,y,temp):
                return True
    return False

result = False
for candidate in combinations(candidates,3):
    temp = copy.deepcopy(hall)
    for c in list(candidate):
        temp[c[0]][c[1]] = 'O'
        if not process(temp):
            result = True
            break

if result:
    print("YES")
else:
    print("NO")
