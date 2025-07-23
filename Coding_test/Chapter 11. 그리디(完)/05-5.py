from itertools import combinations

n, m = map(int, input().split())
data = list(map(int, input().split()))
answer = sum([1 if x != y else 0 for x, y in combinations(data, 2)])
print(answer)
