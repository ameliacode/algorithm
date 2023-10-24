import heapq

def find_parent(parent, x):
    if parent[x] != x:
        parent[x] = find_parent(parent, parent[x])
    return parent[x]

def union_parent(parent, a, b):
    a = find_parent(parent, a)
    b = find_parent(parent, b)
    if a < b:
        parent[b] = a
    else:
        parent[a] = b

n = int(input())

x = []
y = []
z = []

for i in range(n):
    a,b,c = map(int, input().split())
    x.append([a, i])
    y.append([b, i])
    z.append([c, i])

x.sort()
y.sort()
z.sort()
distances = []
parent = [i for i in range(n+1)]

for i in range(n-1):
    heapq.heappush(distances,(abs(x[i][0] - x[i+1][0]), x[i][1], x[i+1][1]))
    heapq.heappush(distances,(abs(y[i][0] - y[i+1][0]), y[i][1], y[i+1][1]))
    heapq.heappush(distances,(abs(z[i][0] - z[i+1][0]), z[i][1], z[i+1][1]))

total_cost = 0
result = 0
while distances and result < n - 1:
    cost, a, b = heapq.heappop(distances)
    if find_parent(parent, a) != find_parent(parent, b):
        union_parent(parent, a, b)
        total_cost += cost
        result += 1

print(total_cost)