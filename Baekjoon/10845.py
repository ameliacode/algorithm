import sys
from collections import deque

n = int(input())

q = deque()
for _ in range(n):
    oper = sys.stdin.readline().strip().split()
    if oper[0] == "push":
        q.append(int(oper[1]))
    elif oper[0] == "pop":
        try:
            print(q.popleft())
        except:
            print(-1)
    elif oper[0] == "size":
        print(len(q))
    elif oper[0] == "empty":
        if len(q) == 0:
            print(1)
        else:
            print(0)
    elif oper[0] == "front":
        if len(q) != 0:
            print(q[0])
        else:
            print(-1)
    elif oper[0] == "back":
        if len(q) != 0:
            print(q[-1])
        else:
            print(-1)
