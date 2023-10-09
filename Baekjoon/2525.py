a,b = map(int, input().split())
c = int(input())

hour = a
minute = b+c
if minute >= 60:
    hour += minute // 60
    minute = minute % 60
    
if hour > 23:
    hour -= 24

print(hour,minute)