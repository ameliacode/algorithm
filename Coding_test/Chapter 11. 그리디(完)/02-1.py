num = input()

answer = int(num[0])
for i in range(1,len(num)):
    if answer+int(num[i]) > answer*int(num[i]):
        answer += int(num[i])
    else:
        answer *= int(num[i])

print(answer)