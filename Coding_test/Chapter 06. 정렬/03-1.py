n = int(input())
array = []

for _ in range(n):
    name, score = input().split()
    array.append((name, int(score)))

array = sorted(array, key=lambda x:x[1])

for i in range(n):
    print(array[i][0], end=' ')