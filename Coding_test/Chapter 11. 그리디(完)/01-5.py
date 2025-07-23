n = int(input())
data = list(map(int, input().split()))
count = sum(data) // n + 1 if sum(data) % n != 0 else sum(data) // n
print(count)
