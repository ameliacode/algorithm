n = int(input())
array = list(map(int, input().split()))

def binary_search(array, start ,end):
    if start > end:
        return None
    mid = (start+end) // 2
    if mid == array[mid]:
        return mid
    elif array[mid] > mid:
        return binary_search(array, start, mid-1)
    else:
        return binary_search(array, mid+1, end)

result = binary_search(array, 0, len(array))
if result:
    print(result)
else:
    print(-1)
 