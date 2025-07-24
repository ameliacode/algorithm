n = int(input())
home = map(int, input().split())

home = sorted(home)
print(home[(n - 1) // 2])
