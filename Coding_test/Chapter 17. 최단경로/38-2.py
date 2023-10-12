n,m = map(int, input().split())
score = [[1e9]*(n+1) for _ in range(n+1)]

for _ in range(m):
    a,b = map(int, input().split())
    score[a][b] = 1

for k in range(1,n+1):
    for i in range(1,n+1):
        for j in range(1,n+1):
            score[i][j] = min(score[i][j], score[i][k]+score[k][j])

answer = 0
for i in range(1,n+1):
    count = 0
    for j in range(1,n+1):
        if score[i][j] != 1e9 or score[j][i] != 1e9:
            count += 1
    if count == n - 1:
        answer += 1
print(answer)