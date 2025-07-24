def solution(N, stages):
    stages.sort()
    players = [[i + 1, stages.count(i + 1), 0] for i in range(N)]
    total = len(stages)

    for idx in range(len(players)):
        players[idx][2] = players[idx][1] / total
        total -= players[idx][1]

    players = sorted(players, key=lambda x: x[2], reverse=True)
    print([player[0] for player in players])


solution(5, [2, 1, 2, 6, 2, 4, 3, 3])
solution(4, [4, 4, 4, 4, 4])
