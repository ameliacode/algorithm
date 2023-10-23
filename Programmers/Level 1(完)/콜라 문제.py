def solution(a,b,n):
    answer = []
    while n >= a :
        coke = (n // a)*b
        answer.append(coke)
        bottles = n % a + coke
        n = bottles
    return sum(answer)

print(solution(2, 1, 20))
print(solution(3, 1, 20))
