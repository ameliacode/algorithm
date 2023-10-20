def solution(number, limit, power):
    array = [i for i in range(1, number+1)]
    answer = []
    for data in array:
        d= []
        for i in range(1, int(data**0.5)+1):
            if data % i == 0:
                d.append(i)
                if i != data // i:
                    d.append(data//i)
        answer.append(len(set(d)))
    
    answer = sum([a if a <= limit else power for a in answer])
    return answer