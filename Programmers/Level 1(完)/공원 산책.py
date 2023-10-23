def solution(park, routes):
    answer = []
    n = len(park)
    m = len(park[0])
    
    dx = [-1,0,1,0]
    dy = [0,-1,0,1]
    directions = {"E":3,"W":1,"S":2,"N":0}
    
    for i in range(n):
        for j in range(m):
            if park[i][j] == 'S':
                start = [i,j]
                break
                
    for route in routes:
        direction, coord = route.split()
        blocked = False
        nx = start[0]
        ny = start[1]
        for _ in range(int(coord)):
            nx += dx[directions[direction]]
            ny += dy[directions[direction]]
            if not (0 <= nx < n and 0 <= ny < m and park[nx][ny] != 'X'):
                blocked = True
                break
        if not blocked:
            start = [nx, ny]
    answer = start
    return answer