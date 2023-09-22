from itertools import combinations

n = int(input())
teachers = []
spaces = []
board = []
for i in range(n):
    board.append(list(input().split()))
    for j in range(n):
        if board[i][j] == 'T':
            teachers.append((i,j))
        if board[i][j] == 'X':
            spaces.append((i,j))


def watch(x, y, direction):
    if direction == 0:
        while x >= 0:
            if board[y][x] == 'S':
                return True
            if board[y][x] == 'O':
                return False
            x -= 1
    if direction == 1:
        while x < n:
            if board[y][x] == 'S':
                return True
            if board[y][x] == 'O':
                return False
            x += 1
    if direction == 2:
        while y >= 0:
            if board[y][x] == 'S':
                return True
            if board[y][x] == 'O':
                return False
            y -= 1
    if direction == 3:
        while y < n:
            if board[y][x] == 'S':
                return True
            if board[y][x] == 'O':
                return False
            y += 1

def process(x,y):
    for y,x in teachers:
        for i in range(4):
            if watch(x,y,i):
                return True
    return False

find = False

for data in combinations(spaces, 3):
    for y,x in data:
        board[y][x] = 'O'
    if not process(x,y):
        find = True
        break
    for y,x in data:
        board[y][x] = 'X'

if find:
    print("YES")
else:
    print("NO")
