n = int(input())
shirts = list(map(int, input().split()))
t, p = map(int, input().split())

start = 0
end = max(shirts)

count = 0
for shirt in shirts:
    cnt = shirt // t
    if shirt % t != 0:
        cnt += 1
    count += cnt
print(count)
print(n // p, n - p * (n // p))
