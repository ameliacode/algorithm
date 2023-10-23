def solution(sizes):
    max_row, max_col = 0,0
    for i in range(len(sizes)):
        if sizes[i][0] < sizes[i][1]:
            sizes[i][0], sizes[i][1] = sizes[i][1], sizes[i][0]
        max_row = max(max_row, sizes[i][0])
        max_col = max(max_col, sizes[i][1])
    answer = max_row*max_col
    return answer