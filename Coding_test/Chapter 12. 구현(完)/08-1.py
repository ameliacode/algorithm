N = input()
alphabet = "".join(sorted([n for n in N if not n.isdigit()]))
num  = sum([int(n) for n in N if n.isdigit()])
result = alphabet + str(num)

print(result)
