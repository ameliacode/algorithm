n = int(input())
array = list(map(int,input().split()))
array.sort(reverse=True)

idx = 0
count = 0
while idx < n:
    count += 1
    idx += array[idx]
    
print(count)