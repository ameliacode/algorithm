n,m = map(int, input().split())
graph = []

for _ in range(m):
    x,y,z = map(int, input().split())
    graph.append((z,x,y))

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

parent = [i for i in range(n)]

graph.sort()
result = 0
total = 0

for g in graph:
    cost,x,y = g
    total += cost
    if find_parent(parent,x) != find_parent(parent,y):
        union_parent(parent, x, y)
        result += cost

print(total - cost)

