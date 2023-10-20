from collections import deque 
def solution(n, m, section):
    dq=deque(section)
    cnt=1
    flag=section[0]+m-1
    
    while dq:
        if dq[0]<=flag:
            dq.popleft()
        else:
            cnt+=1
            flag=dq[0]+m-1
    return cnt