n, c = map(int, input().split())
array = []
for _ in range(n):
    array.append(int(input()))

array.sort()
start = array[1] - array[0]
end = array[-1] - array[0]

while start <= end:
    mid = (start+end) // 2
    value = array[0]
    count = 1
    for i in range(len(array)):
        if value+mid <= array[i]:
            count += 1
            value = array[i]
    if count >= c:
        start = mid + 1
        result = mid
    else:
        end = mid - 1

print(result)
