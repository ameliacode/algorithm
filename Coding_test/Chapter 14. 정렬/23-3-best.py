n = int(input())

data = []
for _ in range(n):
    name, x, y, z = input().split()
    data.append([name, int(x), int(y), int(z)])

data = sorted(data, key = lambda x:x[0])
data = sorted(data, key = lambda x:x[3], reverse=True)
data = sorted(data, key = lambda x:x[2])
data = sorted(data, key = lambda x:x[1], reverse=True)

for i in range(n):
    print(data[i][0])