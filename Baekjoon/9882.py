cows = []
for _ in range(12):
    cows.append(int(input()))

cows.sort()
answer = float("inf")
visited = [False] * 12


def recurrent(sum_val, idx, count, team, min_skill, max_skill):
    global answer

    if team == 4:
        answer = min(answer, max_skill - min_skill)
        return

    if count == 3:
        new_min = min(sum_val, min_skill)
        new_max = max(sum_val, max_skill)
        recurrent(0, 0, 0, team + 1, new_min, new_max)
        return

    for j in range(idx, 12):
        if visited[j]:
            continue
        visited[j] = True
        recurrent(sum_val + cows[j], j + 1, count + 1, team, min_skill, max_skill)
        visited[j] = False


recurrent(0, 0, 0, 0, float("inf"), 0)
print(answer)
