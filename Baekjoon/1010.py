t = int(input())

for _ in range(t):
    n, m = map(int, input().split())

    numerator = 1
    for i in range(m, max(m - n, n), -1):
        numerator *= i

    denominator = 1
    for i in range(min(m - n, n), 0, -1):
        denominator *= i

    answer = numerator // denominator
    print(answer)
