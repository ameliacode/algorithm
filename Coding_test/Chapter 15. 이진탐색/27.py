import sys
from bisect import bisect_left, bisect_right
n,x = map(int, input().split())
array = list(map(int, sys.stdin.readline().split()))

def count_by_range(array, left_value, right_value):
    right_index = bisect_right(array, right_value)
    left_index = bisect_left(array, left_value)
    return right_index - left_index

count = count_by_range(array, x, x)

if count:
    print(count)
else:
    print(-1)