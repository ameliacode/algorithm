isbn = input()
aster_index = isbn.index("*")

check = 0
for i in range(len(isbn)):
    if i == aster_index:
        continue
    if i % 2 == 0:
        check += int(isbn[i])
    else:
        check += 3 * int(isbn[i])

if aster_index % 2 == 0:
    answer = 10 - (check % 10)
else:
    for i in range(10):
        if (3 * i + check) % 10 == 0:
            answer = i
            break
print(answer)
