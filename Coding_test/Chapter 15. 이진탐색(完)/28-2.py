n = int(input())
data = list(map(int, input().split()))


def binary_search(data, start, end):
    if start > end:
        return None
    mid = (start + end) // 2
    if data[mid] == mid:
        return mid
    elif data[mid] > mid:
        return binary_search(data, start, mid - 1)
    else:
        return binary_search(data, mid + 1, end)


result = binary_search(data, 0, n)
if result:
    print(result)
else:
    print(-1)
