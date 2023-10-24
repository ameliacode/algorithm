import heapq
INF = int(1e9)

n, m = map(int, input().split())

graph = [[] for _ in range(n+1)]
distance = [INF] * (n+1)

for _ in range(m):
    a, b = map(int, input().split())
    graph[a].append([b, 1])
    graph[b].append([a, 1])

start = 1
q = []
heapq.heappush(q,(0,start))
distance[start] = 0

while q:
    dist, now = heapq.heappop(q)
    if distance[now] < dist:
        continue
    for i in graph[now]:
        cost = dist + i[1]
        if cost < distance[i[0]]:
            distance[i[0]] = cost
            heapq.heappush(q, (cost, i[0]))

max_distance = max(distance[1:])
max_index = distance.index(max_distance)
max_count = distance.count(max_distance)

print(max_index, max_distance, max_count )

