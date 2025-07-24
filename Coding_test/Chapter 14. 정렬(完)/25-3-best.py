def solution(N, stages):
    players = [[i + 1, stages.count(i + 1)] for i in range(N)]
    total = len(stages)

    prev = 0
    for i in range(len(players)):
        players[i].append(players[i] / (total - prev))
        prev += players[i][1]

    players = sorted(players, key=lambda x: x[-1])
    print([i[0] for i in players])
