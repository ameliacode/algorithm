n = int(input())
data = list(map(int, input().split()))

data.sort(reverse=True)

count = 0
idx = 0
while idx < n:
    gongpodo = data[idx]
    idx += gongpodo
    count += 1

print(count)

