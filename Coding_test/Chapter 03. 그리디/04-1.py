import math
n, k = map(int, input().split())

count = int(math.log(n)/math.log(k))
result = count + (n - k **count)
print(result)