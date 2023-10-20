g = int(input())
p = int(input())

parent = [i for i in range(g+1)]
result = 0

def find_parent(parent, x):
    if parent[x] != x:
        parent[x] = find_parent(parent, parent[x])
    return parent[x]

def union_parent(parent,a,b):
    a = find_parent(parent, a)
    b = find_parent(parent, b)
    if a < b:
        parent[b] = a
    else:
        parent[a] = b

planes = []
for _ in range(p):
    planes.append(int(input()))

for i in range(p):
    data = find_parent(parent, planes[i])
    if data != 0:
        union_parent(parent, data-1, data)
        result += 1
    else:
        break

print(result)



