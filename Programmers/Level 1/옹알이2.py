def solution(babbling):
    talk = ["aya", "ye", "woo", "ma"]
    for i in range(len(talk)):
        for j in range(len(babbling)):
            if talk[i] in babbling[j]:
                babbling[j] = babbling[j].replace(talk[i], str(i))
    answer = 0
    for babble in babbling:
        if babble.isdigit():
            if len(babble) >= 2:
                if not "00" in babble and not "11" in babble and not "22" in babble and not "33" in babble:
                    answer += 1
            elif len(babble) == 1:
                answer += 1      
    return answer

print(solution(	["ayaye", "uuu", "yeye", "yemawoo", "ayaayaa"]))