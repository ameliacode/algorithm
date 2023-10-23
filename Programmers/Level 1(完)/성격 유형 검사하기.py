def solution(survey, choices):
    result = {"R":0, "T":0, "C":0, "F":0, "J":0, "M":0, "A":0, "N":0}
    answer = ''
    
    for idx in range(len(survey)):
        type_a, type_b = survey[idx][0], survey[idx][1]
        if choices[idx] < 4:
            result[type_a] += abs(choices[idx] - 4)
        elif choices[idx] > 4:
            result[type_b] += abs(choices[idx] - 4)
    
    if result["R"] < result["T"]:
        answer += 'T'
    else:
        answer += 'R'
    if result['C'] < result['F']:
        answer += 'F'
    else:
        answer += 'C'
    if result['J'] < result['M']:
        answer += 'M'
    else:
        answer += 'J'
    if result['A'] < result['N']:
        answer += 'N'
    else:
        answer += 'A'
    return answer