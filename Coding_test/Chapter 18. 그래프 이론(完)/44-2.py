import heapq

def find_parent(parent,x):
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
    a,b,c = map(int,input().split())
    x.append((a,i))
    y.append((b,i))
    z.append((c,i))

x.sort()
y.sort()
z.sort()

planets = []

for i in range(n-1):
    heapq.heappush(planets, (abs(x[i+1][0] - x[i][0]), x[i][1], x[i+1][1]))
    heapq.heappush(planets, (abs(y[i+1][0] - y[i][0]), y[i][1], y[i+1][1]))
    heapq.heappush(planets, (abs(z[i+1][0] - z[i][0]), z[i][1], z[i+1][1]))

result = 0
total_cost = 0
parent = [i for i in range(n)]

while planets and result < n - 1:
    cost,x,y = heapq.heappop(planets)
    if find_parent(parent, x) != find_parent(parent, y):
        union_parent(parent,x,y)
        total_cost += cost
        result += 1

print(total_cost)