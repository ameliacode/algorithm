from itertools import combinations

n, m = map(int, input().split())

chicken = []
home = []
for i in range(n):
    array = list(map(int, input().split()))
    for j in range(n):
        if array[j] == 1:
            home.append((i, j))
        if array[j] == 2:
            chicken.append((i, j))

min_dist = 1e9
for candidate in list(combinations(chicken, m)):
    dist = 0
    for c in candidate:
        temp = []
        for h in home:
            temp.append(abs(c[0] - h[0]) + abs(c[1] - h[1]))
        dist += min(temp)
    min_dist = min(min_dist, dist)

print(dist)
