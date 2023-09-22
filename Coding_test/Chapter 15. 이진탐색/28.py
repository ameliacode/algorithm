import sys

n = int(input())
a = list(map(int, sys.stdin.readline().split()))

def binary_search(array,start, end):
    if start > end:
        return None
    mid = (start + end) // 2
    if array[mid] == mid:
        return mid
    elif array[mid] > mid:
        return binary_search(array, start, mid-1)
    else:
        return binary_search(array, mid+1, end)

# for i in range(n):
#     result = binary_search(a,a[i],0,n-1)
result = binary_search(a, 0, n-1)
if result:
    print(result)
else:
    print(-1)
        
