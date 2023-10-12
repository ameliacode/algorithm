n, m = map(int, input().split())

balls = [i for i in range(1,n+1)]

for _ in range(m):
    i, j = map(int,input().split())
    balls = balls[:i-1]+list(reversed(balls[i-1:j]))+balls[j:]

for i in range(n):
    print(balls[i], end=" ")