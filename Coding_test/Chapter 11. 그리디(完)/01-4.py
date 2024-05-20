n = int(input())
data = list(map(int, input().split()))

data.sort(reverse=True)

count = 0
idx = 0

while idx < len(data):
    idx += data[idx]
    count += 1

print(count)