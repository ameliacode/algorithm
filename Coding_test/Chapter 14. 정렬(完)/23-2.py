import sys

input = sys.stdin.readline

n = int(input())

student = []
for _ in range(n):
    info = list(input().split())
    student.append([info[0], int(info[1]), int(info[2]), int(info[3])])

student_list = sorted(list(student), key=lambda x: x[0])
student_list = sorted(student_list, key=lambda x: x[3], reverse=True)
student_list = sorted(student_list, key=lambda x: x[2])
student_list = sorted(student_list, key=lambda x: x[1], reverse=True)

for student in student_list:
    print(student[0])
