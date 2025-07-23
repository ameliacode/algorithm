s = input()

result = 0
for num in s:
    if int(num) <= 1 or result <= 1:
        result += int(num)
    else:
        result *= int(num)

print(result)
