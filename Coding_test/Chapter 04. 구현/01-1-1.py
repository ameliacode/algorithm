n = int(input())
directions = list(input().split())

x,y = 1,1

for direction in directions:
    if direction == 'L' and x > 1:
        x -= 1
    elif direction == 'R' and x <= n:
        x += 1
    elif direction == 'U' and y > 1:
        y -= 1
    elif direction == 'D' and y <= n:
        y += 1
    else:
        pass

print(y, x)