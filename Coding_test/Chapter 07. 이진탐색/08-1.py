n, m = map(int, input().split())
array = list(map(int, input().split()))

array.sort()

start = 0
end = max(array)

reult = 0
while start <= end:
    total = 0
    mid = (start + end) // 2
    for x in array:
        if x > mid:
            total += x - mid

    if total < m:
        end = mid - 1
    else:
        result = mid
        start = mid + 1
print(result)
