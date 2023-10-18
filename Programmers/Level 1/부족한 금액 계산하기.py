def solution(price, money, count):
    usage = sum([i*price for i in range(1,count+1)])
    answer = usage - money
    if answer < 0:
        return 0
    return answer