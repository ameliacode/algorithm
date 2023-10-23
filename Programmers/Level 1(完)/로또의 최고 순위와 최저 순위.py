def solution(lottos, win_nums):
    same = 0
    for w in win_nums:
        if w in lottos:
            same += 1
    possible = lottos.count(0)

    first = same+possible
    second = same
    if first >= 2:
        first = 7-first
    else:
        first = 6
    if second >= 2:
        second = 7 - second
    else:
        second = 6
    return [first, second]

print(solution([44, 1, 0, 0, 31, 25], [31, 10, 45, 1, 6, 19]))
print(solution([45, 4, 35, 20, 3, 9], [20, 9, 3, 45, 4, 35]))
print(solution([0, 0, 0, 0, 0, 0], [38, 19, 20, 40, 15, 25]))