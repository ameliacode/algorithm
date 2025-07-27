import sys

t = int(input())
for case in range(t):
    n = int(input())

    array = list(map(int, sys.stdin.readline().split()))
    answer = 2
    count = 2
    for i in range(2, len(array)):
        if array[i - 2] - array[i - 1] == array[i - 1] - array[i]:
            count += 1
        else:
            count = 2
        answer = max(answer, count)
    print(f"Case #{case+1}: {answer}")
