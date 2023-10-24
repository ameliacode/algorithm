s = input()

result = 0
for i in range(len(s)):
    num = int(s[i])
    if i == 0:
        result = num
    else:
        if result <= 1 or num <= 1: # 두 수 중 하나라도 0 or 1
            result += num
        else:
            result *= num

print(result)
