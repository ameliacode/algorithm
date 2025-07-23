from itertools import combinations

n, m = map(int, input().split())
balls = list(map(int, input().split()))

candidates = list(combinations(balls, 2))

count = 0
for candidate in candidates:
    if candidate[0] == candidate[1]:
        count += 1

answer = len(candidates) - count
print(answer)
