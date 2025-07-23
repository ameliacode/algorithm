n = input()
length = len(n)

one = sum([int(num) for num in n[: length // 2]])
two = sum([int(num) for num in n[length // 2 :]])

if one == two:
    print("LUCKY")
else:
    print("READY")
