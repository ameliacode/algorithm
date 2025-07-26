import sys
from collections import deque

n, m, k, x = map(int, input().split())
graph = [[] for _ in range(n + 1)]

for _ in range(m):
    a, b = map(int, sys.stdin.readline().split())
    graph[a].append(b)

queue = deque([x])
visited = [1e9 for _ in range(n + 1)]
visited[x] = 0

while queue:
    x = queue.popleft()
    for i in graph[x]:
        if visited[i] == 1e9:
            queue.append(i)
            visited[i] = min(visited[i], visited[i] + 1)

if k in visited[1:]:
    for i in range(1, n + 1):
        if visited[i] == k:
            print(i)
else:
    print(-1)
