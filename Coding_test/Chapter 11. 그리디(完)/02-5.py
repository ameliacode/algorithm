s = input()
answer = 0
for i in s:
    i = int(i)
    if answer <= 1 or i <= 1:
        answer += i
    else:
        answer *= i
print(answer)
