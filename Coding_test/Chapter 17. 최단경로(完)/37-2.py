import sys

input = sys.stdin.readline

n = int(input())
m = int(input())

adj = [[1e9] * (n+1) for _ in range(n+1)]

for _ in range(m):
    a,b,c = map(int, input().split())
    adj[a][b] = min(adj[a][b], c)

for k in range(1,n+1):
    for i in range(1,n+1):
        for j in range(1,n+1):
            if i != j:
                adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]) 

for i in range(1,n+1):
    for j in range(1,n+1):
        if adj[i][j] == 1e9:
            print(0, end=" ")
        else:
            print(adj[i][j], end=" ")
    print()