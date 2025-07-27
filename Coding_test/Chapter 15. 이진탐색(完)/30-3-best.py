from bisect import bisect_left, bisect_right

array = {}
reversed_array = {}


def solution(words, queries):
    answer = [0] * len(queries)
    # initialize
    for word in words:
        if not len(word) in array.keys():
            array[len(word)] = [word]
        else:
            array[len(word)].append(word)
        if not len(word) in reversed_array.keys():
            reversed_array[len(word)] = [word[::-1]]
        else:
            reversed_array[len(word)].append(word[::-1])

    for key in array.keys():
        array[key].sort()
        reversed_array[key].sort()

    for i in range(len(queries)):
        length = len(queries[i])
        if not length in array.keys():
            answer[i] = 0
            continue
        if queries[i].startswith("?"):
            query = queries[i][::-1]
            left = bisect_left(reversed_array[length], query.replace("?", "a"))
            right = bisect_right(reversed_array[length], query.replace("?", "z"))
            answer[i] = right - left
        else:
            left = bisect_left(array[length], queries[i].replace("?", "a"))
            right = bisect_right(array[length], queries[i].replace("?", "z"))
            answer[i] = right - left
    return answer


result = solution(
    ["frodo", "front", "frost", "frozen", "frame", "kakao"],
    ["fro??", "????o", "fr???", "fro???", "pro?"],
)
print(result)
