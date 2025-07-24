chess = []

for _ in range(8):
    chess.append(input())

answer = 0
for i in range(8):
    for j in range(8):
        if (i + j) % 2 == 0 and chess[i][j] == "F":
            answer += 1


print(answer)
