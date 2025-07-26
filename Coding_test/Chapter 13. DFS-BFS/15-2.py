from collections import deque

n, m, k, x = map(int, input().split())

graph = [[] for _ in range(n + 1)]

for _ in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)

dist = [-1] * (n + 1)


def bfs(graph, start):
    queue = deque([start])
    dist[start] = 0
    while queue:
        v = queue.popleft()
        for i in graph[v]:
            if dist[i] == -1:
                queue.append(i)
                dist[i] = dist[v] + 1


bfs(graph, x)

check = False
for idx in range(1, n + 1):
    if dist[idx] == k:
        print(idx)
        check = True

if not check:
    print(-1)
