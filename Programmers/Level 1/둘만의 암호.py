def solution(s, skip, index):
    diff = set([chr(i) for i in range(97,123)]) - set(list(skip))
    diff = sorted(list(diff))
    answer = ""
    for i in range(len(s)):
        idx = (diff.index(s[i]) + index) % len(diff)
        answer += diff[idx]
    return answer