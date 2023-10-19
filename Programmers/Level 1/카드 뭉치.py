def solution(cards1, cards2, goal):
    for g in goal:
        if cards1 and g == cards1[0]:
            del cards1[0]
        elif cards2 and g == cards2[0]:
            del cards2[0]
        else:
            return "No"
    return 'Yes'

print(solution(["i", "drink", "water"], 
               ["want", "to"], 
               ["i", "want", "to", "drink", "water"]))
print(solution(["i", "water", "drink"], 
               ["want", "to"], 
               ["i", "want", "to", "drink", "water"]))