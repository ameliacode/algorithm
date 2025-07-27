n = int(input())

array = []
array.append(0)
for i in range(1, n + 1):
    a = array[i - 1] - i
    if a < 0 or a in array:
        array.append(array[i - 1] + i)
    else:
        array.append(a)

print(array[n])
