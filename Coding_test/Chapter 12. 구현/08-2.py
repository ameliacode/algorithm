s = list(input())
s.sort()

num = sum([int(i) for i in s if i.isdigit()])
string = ''.join([i for i in s if not i.isdigit()])

print(string+str(num))
