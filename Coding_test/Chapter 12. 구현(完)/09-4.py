def solution(s):
    answer = len(s)
    for length in range(1, len(s)):
        new_string = ""
        prev = ""
        i = 0
        count = 1
        while i <= len(s) - length:
            now = s[i:i+length]
            if prev == now:
                count += 1
            else:
                if count > 1:
                    new_string += str(count)+prev
                else:
                    new_string += prev
                count = 1
            prev = now
            i += length
        answer = min(answer, len(new_string))
    return answer

print(solution("ababcdcdababcdcd"))
print(solution("abcabcdede"))
print(solution("abcabcabcabcdededededede"))
print(solution("xababcdcdababcdcd"))