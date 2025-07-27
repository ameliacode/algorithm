n = int(input())

idx2, idx3, idx5 = 0, 0, 0
next2, next3, next5 = 2, 3, 5
ugly = [0] * n
ugly[0] = 1

for idx in range(1, n):
    ugly[idx] = min(next2, next3, next5)
    if ugly[idx] == next2:
        idx2 += 1
        next2 = ugly[idx2] * 2

    if ugly[idx] == next3:
        idx3 += 1
        next3 = ugly[idx3] * 3

    if ugly[idx] == next5:
        idx5 += 1
        next5 = ugly[idx5] * 5

print(ugly[n - 1])
