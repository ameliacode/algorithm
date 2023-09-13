N = int(input())
X = input()
X = [int(n) for n in X.split(" ")]
X = sorted(X, reverse=True)

answer = 0
idx = 0
while idx < len(X):
    answer += 1
    idx += X[idx]

print(answer)
