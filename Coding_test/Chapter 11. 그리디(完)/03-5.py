s = input()

zeros = [i for i in s.split("1") if i != ""]
ones = [i for i in s.split("0") if i != ""]
answer = min(len(zeros), len(ones))
print(answer)
