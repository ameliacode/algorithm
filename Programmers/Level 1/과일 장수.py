def solution(k, m, score):
    score.sort(reverse=True)
    answer = sum([min(score[i:i+m])*m if len(score[i:i+m]) == m else 0 for i in range(0,len(score), m)])
    return answer