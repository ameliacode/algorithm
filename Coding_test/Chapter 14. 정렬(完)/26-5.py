import heapq

n = int(input())

q = []
total = []

for _ in range(n):
    heapq.heappush(q, int(input()))

while q:
    a = heapq.heappop(q)
    try:
        b = heapq.heappop(q)
        heapq.heappush(q, (a + b))
        total.append(a + b)
    except:
        pass
print(sum(total))
