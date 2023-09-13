N = int(input())
coins = input()
coins = [int(n) for n in coins.split(" ")]
comb = []


length = 1
while length < N:
    for i in range(N):
        comb.append(sum(coins[i:i+length]))
    length += 1

comb = list(set(sorted(comb)))
nums = range(1, max(comb))

for n in nums:
    if not n in comb:
        answer = n
        break

print(n)