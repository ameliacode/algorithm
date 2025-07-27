array = list(map(int, input().split()))

answer = 0
for num in array:
    answer += num**2
answer = answer % 10
print(answer)
