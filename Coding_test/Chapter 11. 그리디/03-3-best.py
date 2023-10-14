s = input()

zeros = [i for i in s.split("1") if len(i)]
ones = [i for i in s.split("0") if len(i)]

print(min(len(zeros), len(ones)))