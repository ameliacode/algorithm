n = 1260
count = 0

while n > 0:
    if n >= 500:
        count += 1
        n -= 500
    elif n >= 100:
        count += 1
        n -= 100
    elif n >= 50:
        count += 1
        n -= 50
    elif n >= 10:
        count += 1
        n -= 10

print(count)