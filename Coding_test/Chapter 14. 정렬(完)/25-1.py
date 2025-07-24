def solution(N, stages):
    players = [[i + 1, stages.count(i + 1), 0] for i in range(N)]
    total_num = len(stages)
    prev_players = 0
    for i in range(N):
        if players[i][1] != 0:
            players[i][2] = players[i][1] / (total_num - prev_players)
        else:
            players[i][1] = 0
        prev_players += players[i][1]
    players = sorted(players, key=lambda x: x[2], reverse=True)
    answer = [n[0] for n in players]
    return answer
