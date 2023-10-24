n = int(input())
m = int(input())

adj = [[1e9] *(n+1) for _ in range(n+1)]
for i in range(1,n+1):
    adj[i][i] = 0

for _ in range(m):
    a,b,c = map(int,input().split())
    adj[a][b] = min(adj[a][b], c)

for k in range(1,n+1):
    for a in range(1, n+1):
        for b in range(1, n+1):
            adj[a][b] = min(adj[a][b], adj[a][k]+adj[k][b])

for a in range(1,n+1):
    for b in range(1,n+1):
        if adj[a][b] == 1e9:
            print(0, end=" ")
        else:
            print(adj[a][b], end=" ")
    print()