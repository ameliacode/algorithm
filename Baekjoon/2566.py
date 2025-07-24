import heapq

q = []
for i in range(9):
    row = list(map(int, input().split()))
    max_val = max(row)
    max_idx = row.index(max_val)

    if len(q) < 1:
        heapq.heappush(q, (max_val, max_idx, i))
    else:
        prev_max, prev_col, prev_row = heapq.heappop(q)
        if prev_max < max_val:
            heapq.heappush(q, (max_val, max_idx, i))
        else:
            heapq.heappush(q, (prev_max, prev_col, prev_row))

print(q[-1][0])
print(q[-1][2] + 1, q[-1][1] + 1)  # row, column (adjusted to 1-based index)
