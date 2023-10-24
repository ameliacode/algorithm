import heapq

n,m = map(int, input().split())

graph = [[] for _ in range(n+1)]
for _ in range(m):
    a, b = map(int, input().split())
    graph[a].append((b,1))
    graph[b].append((a,1))

distance = [1e9] * (n+1)
q = []
heapq.heappush(q,(0,1))
distance[1] = 0

while q:
    dist, now = heapq.heappop(q)
    if distance[now] < dist:
        continue
    for i in graph[now]:
        cost = dist + i[1]
        if cost < distance[i[0]]:
            distance[i[0]] = cost
            heapq.heappush(q,(cost, i[0]))

distance = [dist if dist!=1e9 else -1 for dist in distance[1:]]

print(distance.index(max(distance))+1, max(distance), distance.count(max(distance)))