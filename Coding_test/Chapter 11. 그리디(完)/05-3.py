from itertools import combinations

n, m = map(int, input().split())
balls = list(map(int, input().split()))

count = 0
for candidate in list(combinations(balls, 2)):
    if candidate[0] == candidate[1]:
        count += 1

print(len(list(combinations(balls, 2))) - count)
