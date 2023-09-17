def solution(s):
    answer = len(s)
    for length in range(1,len(s)):
        idx = 0
        count = 0
        prev = ""
        new_s = ""
        while idx < len(s) + length:
            if len(prev) == 0:
                count += 1
            elif prev == s[idx:idx+length]:
                count += 1
            else:
                if count >= 2:
                    new_s += str(count)+prev
                else:
                    new_s += prev
                count = 1
            prev = s[idx:idx+length]
            idx += length
        if len(new_s) < answer:
            answer = len(new_s)
    return answer