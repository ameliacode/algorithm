import re
from copy import deepcopy

def solution(new_id):
    answer = deepcopy(new_id)
    answer = answer.lower()
    answer = re.sub(r'[^a-zA-Z0-9\-_\.]', '', answer)
    answer = re.sub(r'\.{2,}', '.', answer)

    while answer.startswith('.') or answer.endswith('.'):
        if answer.startswith('.'):
            answer = answer[1:]
        if answer.endswith('.'):
            answer = answer[:-1]
            
    if answer == "":
        answer += 'a'
        
    if len(answer) >= 16:
        answer = answer[:15]
        if answer.endswith('.'):
            answer = answer[:-1]
            
    if len(answer) <= 2:
        answer += answer[-1] * (3-len(answer))
    return answer