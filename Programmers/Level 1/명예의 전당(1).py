def solution(k, score):
    answer = []
    temp = []
    for idx in range(len(score)):
        temp.append(score[idx])
        if len(temp) > k:
            temp.remove(min(temp))
        answer.append(min(temp))
    return answer