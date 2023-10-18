def solution(t, p):
    answer = 0
    for i in range(len(t)):
        number = t[i:i+len(p)]
        if int(number) <= int(p) and len(number) == len(p):
            answer += 1
    return answer

print(solution("10203","15"))
print(solution("3141592", "271"))