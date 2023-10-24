def solution(N, stages):
    players = [[i+1, stages.count(i+1)] for i in range(N)]
    fails = []
    total = len(stages) 
    prev = 0
    for i in range(N):  # Change range from 0 to 1
        if players[i][1] == 0:
            fails.append([i+1, 0])
        else:
            fails.append([i+1, players[i][1] / (total - prev)])
        prev += players[i][1]

    fails = sorted(fails, key=lambda x: x[1], reverse=True) 
    answer = [x[0] for x in fails]
    return answer