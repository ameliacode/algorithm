s = input()

strings = "".join(sorted([i for i in s if i.isalpha()]))
nums = sum([int(i) for i in s if i.isdigit()])

print(strings + str(nums))
