n = input()
first = sum(int(num) for num in n[: len(n) // 2])
second = sum(int(num) for num in n[len(n) // 2 :])
print("LUCKY" if first == second else "READY")
