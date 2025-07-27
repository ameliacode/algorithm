from bisect import bisect_left, bisect_right

n, m = map(int, input().split())
array = list(map(int, input().split()))

left = bisect_left(array, m)
right = bisect_right(array, m)

if right - left:
    print(right - left)
else:
    print(-1)
