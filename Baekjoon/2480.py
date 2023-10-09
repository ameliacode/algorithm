a,b,c=map(int, input().split())

result = 0
if a == b == c:
    result = 10000 + 1000*a
elif a != b and a!= c and b!=c:
    result = 100*max(a,b,c)
else:
    if a == b:
        same = a
    elif b == c:
        same = b
    elif c == a:
        same = c
    result = 1000+same*100 

print(result)