from itertools import combinations

n = int(input())
coins = list(map(int, input().split()))

coins.sort()
candidates = []

for i in range(1, n+1):
    for j in list(combinations(coins, i)):
        add = sum(list(j)) 
        candidates.append(add)

idx = 1
result = 0
for i in list(set(candidates)):
    if i == idx:
        idx += 1
    else:
        result = idx
        break

print(idx)