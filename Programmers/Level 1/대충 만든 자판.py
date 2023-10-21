def solution(keymap, targets):
    answer = []
    for t in targets:
        total = 0
        for i in t:
            count = [k.index(i)+1 if i in k else 1e9 for k in keymap ]   
            total += min(count)
            print(min(count))
        if total >= 1e9:
            answer.append(-1)
        else:
            answer.append(total)
    return answer