n = int(input())

a = list(map(int, input().split()))
calc = list(map(int, input().split()))

min_value = 1e9
max_value = -1e9


def recurrent(idx, result):
    global calc, min_value, max_value
    if idx == n:
        min_value = min(min_value, result)
        max_value = max(max_value, result)

    for i in range(4):
        if calc[i] > 0:
            if i == 0:  # add
                calc[i] -= 1
                recurrent(idx + 1, result + a[idx])
                calc[i] += 1
            if i == 1:  # sub
                calc[i] -= 1
                recurrent(idx + 1, result - a[idx])
                calc[i] += 1
            if i == 2:  # mul
                calc[i] -= 1
                recurrent(idx + 1, result * a[idx])
                calc[i] += 1
            if i == 3:  # div
                calc[i] -= 1
                recurrent(idx + 1, int(result / a[idx]))
                calc[i] += 1


recurrent(1, a[0])
print(max_value)
print(min_value)
