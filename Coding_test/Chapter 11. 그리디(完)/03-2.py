S = input()

zeros = len([s for s in S.split("0") if len(s) != 0])
ones = len([s for s in S.split("1") if len(s) != 0])

print(min(zeros, ones))
