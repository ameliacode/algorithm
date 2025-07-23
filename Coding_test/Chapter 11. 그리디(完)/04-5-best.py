from itertools import combinations

n = int(input())
coins = list(map(int, input().split()))

candidates = set()
for i in range(n):
    combs = list(combinations(coins, i + 1))
    for comb in combs:
        candidates.add(sum(comb))

answer = 1
while True:
    if answer not in candidates:
        break
    answer += 1

print(answer)
