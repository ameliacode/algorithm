from itertools import permutations


def solution(n, weak, dist):
    length = len(weak)
    for i in range(length):
        weak.append(weak[i] + n)
    answer = len(dist) + 1
    for start in range(length):
        count = 1
        for friend in list(permutations(dist, len(dist))):
            position = weak[start] + friend[count - 1]
            for index in range(start, start + length):
                if position < weak[index]:
                    count += 1
                    if count > len(dist):
                        break
                    position = weak[index] + friend[count - 1]
            answer = min(answer, count)
    if answer > len(dist):
        return -1
    return count
