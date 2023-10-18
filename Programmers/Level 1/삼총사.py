from itertools import combinations

def solution(number):
    answer = 0
    for combs in list(combinations(number, 5)):
        print(combs)
        if sum(combs) == 0:
            answer += 1
    return answer

print(solution([-2, 3, 0, 2, -5]))