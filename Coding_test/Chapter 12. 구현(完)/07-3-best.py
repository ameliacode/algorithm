n = input()

a = sum([int(i) for i in n[:len(n)//2]])
b = sum([int(i) for i in n[len(n)//2:]])

if a == b:
    print("LUCKY")
else:
    print("READY")