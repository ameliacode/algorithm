n = int(input())
s = str(n)

a = sum(list(map(int, s[:len(s)//2])))
b = sum(list(map(int, s[len(s)//2:])))

if a == b:
    print("LUCKY")
else:
    print("READY")