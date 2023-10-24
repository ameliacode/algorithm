import itertools

n = int(input())
coins = list(map(int, input().split()))

coins.sort()

result = 1
cases = []

for num in range(1,n+1):
    comb = itertools.combinations(coins, num)
    for c in comb:
        total = sum(c)
        cases.append(total)

cases=list(set(sorted(cases)))

for n in cases:
    if n == result:
        result += 1
    else:
        break

print(result)

