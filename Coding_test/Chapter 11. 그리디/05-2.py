import itertools

n, m = map(int, input().split())
balls = list(map(int, input().split()))
comb = list(itertools.combinations(balls, 2))
same_case = sum([1 if c[0] == c[1] else 0 for c in comb])

print(len(comb) - same_case)