import sys

n = int(input())
cards = list(map(int, sys.stdin.readline().strip().split()))
m = int(input())
sangeun = list(map(int, sys.stdin.readline().strip().split()))

answer = {}

for card in cards:
    if card in answer:
        answer[card] += 1
    else:
        answer[card] = 1

for num in sangeun:
    count = answer.get(num)
    if count == None:
        print(0, end=" ")
    else:
        print(count, end=" ")
