n,m = map(int,input().split())

adj = [[1e9] * (n+1) for _ in range(n+1)]
for _ in range(m):
    a, b = map(int,input().split())
    adj[a][b] = 1

for k in range(1,n+1):
    for a in range(1,n+1):
        for b in range(1,n+1):
            adj[a][b] = min(adj[a][b], adj[a][k]+adj[k][b])

answer = 0
for i in range(1,n+1):
    count = 0
    for j in range(1,n+1):
        if adj[i][j] != 1e9 or adj[j][i] != 1e9:
            count += 1
    if count == n - 1:
        answer += 1
print(answer)
