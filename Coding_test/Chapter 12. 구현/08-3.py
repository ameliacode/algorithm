s = list(input())
s.sort()

string = [i for i in s if not i.isdigit()]
digit = sum([int(i) for i in s if i.isdigit()])

print("".join(string)+str(digit))
