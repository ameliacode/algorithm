def solution(X, Y):
    common = set(X).intersection(set(Y))
    
    if common:
        answer = [n * min(list(X).count(n), list(Y).count(n)) for n in common]
        answer.sort(reverse=True)
        answer= "".join(answer)
        if answer.startswith("0"):
            return "0"
        else:
            return answer
    else:
        return "-1"