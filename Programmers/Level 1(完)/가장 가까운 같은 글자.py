def solution(s):
    answer = [-1]*len(s)
    for length in range(1,len(s)):
        current = s[length]
        for i in range(len(s[:length])):
            if s[i] == current:
                answer[length] = length-i
    return answer