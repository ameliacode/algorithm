s = input()
s.sort()

alpha = "".join([i for i in list(s) if i.isalpha()])
numbers = sum([int(i) for i in list(s) if i.isdigit()])

print(alpha + str(numbers))
