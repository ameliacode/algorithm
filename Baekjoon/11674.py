s = input()

x = 0
y = 0
for i in range(len(s)):
    x = 2 * x
    y = 2 * y
    if s[i] == "0":
        pass
    if s[i] == "1":
        x += 1
    if s[i] == "2":
        y += 1
    if s[i] == "3":
        x += 1
        y += 1

print(len(s), x, y)
