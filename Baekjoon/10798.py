from collections import deque

data = deque()

for _ in range(5):
    data.append("".join(input().split()))

answer = ""
while data:
    s = data.popleft()
    if len(s) > 0:
        answer += s[0]
        data.append(s[1:])
print(answer)
