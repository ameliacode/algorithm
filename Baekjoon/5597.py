student = []

for _ in range(28):
    student.append(int(input()))

for i in range(1, 31):
    if not i in student:
        print(i)