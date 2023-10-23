def solution(players, callings):
    answer = {}
    for idx in range(len(players)):
        answer[players[idx]] = idx 
        
    for call in callings:
        current_rank = answer[call]
        answer[call] -= 1
        answer[players[current_rank - 1]] += 1
        
        players[current_rank - 1], players[current_rank] = call, players[current_rank - 1]
    return players