import itertools

n,m= map(int, input().split())
chicken = []
houses = []
for i in range(n):
    data = list(map(int, input().split()))
    for j in range(n):
        if data[j] == 1:
            houses.append([i,j])
        if data[j] == 2:
            chicken.append([i,j])

combs = list(itertools.combinations(chicken, m))

min_dist = 1e9
for comb in combs:
    dist = 0
    for h in houses:
        temp = []
        for c in comb:
            temp.append(abs(h[0]-c[0])+abs(h[1]-c[1]))
        dist += min(temp)
    if dist < min_dist:
        min_dist = dist

print(min_dist)

