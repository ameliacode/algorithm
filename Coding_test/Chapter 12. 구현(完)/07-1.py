N = input()
length = len(N) // 2
a = sum([int(n) for n in N[:length]])
b = sum([int(n) for n in N[length:]])

if a == b:
    print("LUCKY")
else:
    print("READY")
