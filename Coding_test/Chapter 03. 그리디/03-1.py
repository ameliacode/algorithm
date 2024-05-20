n, m = map(int,input().split())

cards = []
for _ in range(n):
    data = list(map(int, input().split()))
    cards.append(min(data))

print(max(cards))


