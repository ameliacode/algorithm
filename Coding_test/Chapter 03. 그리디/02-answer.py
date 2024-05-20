n,m,k = map(int, input().split())
data = list(map(int, input().split()))

data.sort()
first = data[-1]
second = data[-2]

count = m // (k+1) * k + m % (k+1)
result = count * first + (m - count) * second
print(result)