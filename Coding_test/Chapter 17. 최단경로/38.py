import heapq
INF = int(1e9)

n, m = map(int, input().split())

graph = [[INF]*(n+1) for _ in range(n+1)]

for _ in range(m):
    a, b = map(int, input().split())
    graph[a][b] = 1

for k in range(1,n+1):
    for a in range(1, n+1):
        for b in range(1, n+1):
            if a == b:
                graph[a][b] = 0
            else:
                graph[a][b] = min(graph[a][b], graph[a][k]+graph[k][b])




data = [[INF]*(n+1) for _ in range(n+1)]

for i in range(1,n+1):
    for j in range(1,n+1):
            data[i][j] = min(graph[i][j], graph[j][i])

count = 0
for a in range(1, n+1):
    check = True
    for b in range(1, n+1):
        if data[a][b] == INF:
            check=False
            break
    if check:
        count += 1

print(count)