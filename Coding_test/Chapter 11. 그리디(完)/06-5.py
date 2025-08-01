import heapq


def solution(food_times, k):
    if sum(food_times) <= k:
        return -1

    length = len(food_times)
    q = []
    for i in range(length):
        heapq.heappush(q, (food_times[i], i + 1))

    sum_value = 0
    previous = 0

    while sum_value + (q[0][0] - previous) * length <= k:
        now = heapq.heappop(q)[0]
        sum_value += (now - previous) * length
        length -= 1
        previous = now

    result = sorted(q, key=lambda x: x[1])
    return result[(k - sum_value) % length][1]
