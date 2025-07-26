from itertools import combinations

n, m = map(int, input().split())

chicken = []
houses = []
for x in range(n):
    row = list(map(int, input().split()))
    for y in range(n):
        if row[y] == 2:
            chicken.append([x, y])
        elif row[y] == 1:
            houses.append([x, y])

answer = 1e9
for candidates in list(combinations(chicken, m)):
    dist = 0
    for c in candidates:
        temp = []
        for h in houses:
            temp.append(abs(h[0] - c[0]) + abs(h[1] - c[1]))
        dist += min(temp)
    answer = min(answer, dist)

print(answer)
