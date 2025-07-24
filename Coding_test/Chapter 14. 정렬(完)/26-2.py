import heapq
import sys

input = sys.stdin.readline

n = int(input())
cards = []
for _ in range(n):
    heapq.heappush(cards, (int(input())))

total = []
while len(cards) != 1:
    a = heapq.heappop(cards)
    b = heapq.heappop(cards)
    heapq.heappush(cards, a + b)
    total.append(a)
    total.append(b)

print(sum(total))
