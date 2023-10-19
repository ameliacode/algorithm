def solution(name, yearning, photo):
    score = {}
    for i in range(len(name)):
        score[name[i]] = yearning[i]
    
    answer = []
    for p in photo:
        total = 0
        for i in p:
            if i in score.keys():
                total += score[i]
        answer.append(total)
    return answer