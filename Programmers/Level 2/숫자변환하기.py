from collections import deque


def solution(x, y, n):
    if x >= y:
        return 0 if x == y else -1

    queue = deque([(x, 0)])
    visited = {x}

    while queue:
        current, steps = queue.popleft()
        operations = [current * 2, current * 3, current + n]

        for next_val in operations:
            if next_val == y:
                return steps + 1

            if next_val < y and next_val not in visited:
                visited.add(next_val)
                queue.append((next_val, steps + 1))

    return -1
