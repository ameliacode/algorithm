n = int(input())
a = list(map(int, input().split()))
m = int(input())
checks = list(map(int, input().split()))

a.sort()

for check in checks:
    if check in a:
        print(1)
    else:
        print(0)
