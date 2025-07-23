n = int(input())
students = []
for _ in range(n):
    name, kor, eng, math = input().split()
    students.append([name, int(kor), int(eng), int(math)])

students = sorted(students, key=lambda x: x[0])
students = sorted(students, key=lambda x: x[3], reverse=True)
students = sorted(students, key=lambda x: x[2])
students = sorted(students, key=lambda x: x[1], reverse=True)

for student in students:
    print(student[0])
