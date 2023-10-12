n, m = map(int, input().split())

balls = [i for i in range(1,n+1)]

for _ in range(m):
    i, j = map(int,input().split())
    balls[i-1], balls[j-1] = balls[j-1], balls[i-1]

for i in range(n):
    print(balls[i], end=" ")