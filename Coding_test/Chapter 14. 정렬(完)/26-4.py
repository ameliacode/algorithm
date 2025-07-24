import heapq

n = int(input())

q = []
cards = []

for _ in range(n):
    heapq.heappush(q, int(input()))

answer = 0
while q:
    a = heapq.heappop()
    try:
        b = heapq.heappop()
        heapq.heappush(q, (a + b))
        cards.append(a + b)
    except:
        pass

print(sum(cards))
