n,m = map(int, input().split())

balls = [0] * n

for _ in range(m):
    i,j,k = map(int,input().split())
    for idx in range(i-1,j):
        balls[idx] = k

for b in balls:
    print(b, end=" ")