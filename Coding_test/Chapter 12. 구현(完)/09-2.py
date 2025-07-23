def solution(s):
    answer = s
    for length in range(1, len(s)):
        idx = 0
        count = 0
        prev = ""
        new_s = ""
        while idx < len(s) + length:
            if s[idx : idx + length] == prev or len(prev) == 0:
                count += 1
            else:
                if count >= 2:
                    new_s += str(count) + prev
                else:
                    new_s += prev
                count = 1
            prev = s[idx : idx + length]
            idx += length
        if len(new_s) < len(answer):
            answer = new_s
    return len(answer)
