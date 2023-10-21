def solution(s):
    x = s[0]
    a,b = 0,0
    answer = 1
    start = 0
    for idx in range(len(s)-1):
        if s[idx] == x:
            a += 1
        else:
            b += 1
        print(a,b)
        if a == b:
            answer += 1
            start = idx+1
            x = s[start]
            a,b= 0,0
    return answer