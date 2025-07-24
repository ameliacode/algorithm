n = int(input())
stages = list(map(int, input().split()))

data = {}
for stage in range(1, n + 2):
    data[stage] = 0

for stage in stages:
    data[stage] = stages.count(stage)

data = sorted(data.items(), key=lambda x: x[0])
data = [count for _, count in data]

rate = []
for stage in range(n):
    rate.append((data[stage] / sum(data[stage:]), stage + 1))

answer = sorted(rate, key=lambda x: x[0], reverse=True)
answer = [stage for _, stage in answer]
print(answer)
