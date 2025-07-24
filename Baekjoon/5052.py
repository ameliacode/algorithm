import sys

t = int(input())

for _ in range(t):
    n = int(input())
    phone_numbers = [sys.stdin.readline().rstrip() for _ in range(n)]
    phone_numbers.sort()

    flag = False
    for i in range(1, n):
        if phone_numbers[i].startswith(phone_numbers[0]):
            flag = True
            break

    if flag:
        print("NO")
    else:
        print("YES")
