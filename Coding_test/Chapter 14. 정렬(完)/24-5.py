n = int(input())
distances = list(map(int, input().split()))
distances.sort()
answer = distances[(n - 1) // 2]
print(answer)
