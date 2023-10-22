from collections import deque

n,m,k,x = map(int, input().split())
graph = [[] for _ in range(n+1)]
visited = [1e9] * (n+1)

for _ in range(m):
    a,b = map(int,input().split())
    graph[a].append(b)

queue = deque([x])
visited[x] = 0

while queue:
    v = queue.popleft()
    for i in graph[v]:
        if visited[i] == 1e9:
            queue.append(i)
            visited[i] = min(visited[i], visited[v]+1)

if k in visited[1:]:
    for i in range(1,n+1):
        if k == visited[i]:
            print(i)
else:
    print(-1)