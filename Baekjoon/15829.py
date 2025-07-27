l = int(input())
s = input()

answer = 0
for i in range(0, l):
    answer += (ord(s[i]) - 97 + 1) * 31**i
print(answer % 1234567891)
