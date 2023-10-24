import sys

n = int(input())

scores = {}

for _ in range(n):
    name, k, e, m = sys.stdin.readline().split()
    scores[name] = [int(k),int(e),int(m)]

scores_list = sorted(scores.items(), key=lambda item:item[0])
scores_list = sorted(scores_list, key=lambda x:x[1][2], reverse=True)
scores_list = sorted(scores_list, key=lambda x:x[1][1])
scores_list = sorted(scores_list, key=lambda x:x[1][0], reverse=True)

for info in scores_list:
    print(info[0])
