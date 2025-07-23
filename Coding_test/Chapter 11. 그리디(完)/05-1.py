import numpy as np

N, M = input().split(" ")
N = int(N)
M = int(M)

balls = input()
balls = [int(i) for i in balls.split()]

answer = N * (N - 1) // 2
same_case = 0

for i in range(len(balls)):
    if balls.count(i) == 1:
        balls[i] = 0
answer -= len(set(balls)) - 1
print(answer)
