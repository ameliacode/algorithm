S = input()

answer = 0
zero = [s for s in S.split("1") if len(s) != 0]
ones = [s for s in S.split("0") if len(s) != 0]
swap=[]
if len(zero) > len(ones):
    answer = len(ones)
else:
    answer = len(zero)
print(answer)
