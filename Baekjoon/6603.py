from itertools import combinations

data = []
while True:
    var = list(map(int, input().split()))
    if var[0] == 0:
        break

    k = var[0]
    s = var[1:]

    for candidate in list(combinations(s, 6)):
        for c in candidate:
            print(c, end=" ")
        print()
    print()
