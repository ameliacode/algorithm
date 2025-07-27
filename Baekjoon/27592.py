import sys

n, x = map(int, sys.stdin.readline().split())

a = list(map(int, sys.stdin.readline().split()))
b = list(map(int, sys.stdin.readline().split()))

answer = 0
weight = 0
for i in range(n):
    weight += b[i]
    if weight < a[i]:
        answer = -1
        break
if answer != -1:
    answer = (weight - a[n - 1]) // x
print(answer)
