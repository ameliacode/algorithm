def solution(wallpaper):
    x = []
    y = []
    for i in range(len(wallpaper)):
        for j in range(len(wallpaper[i])):
            if wallpaper[i][j] == '#':
                x.append(i)
                y.append(j)
    
    min_x = min(x)
    min_y = min(y)
    max_x = max(x)
    max_y = max(y)
        
    return [min_x, min_y, max_x+1, max_y+1]