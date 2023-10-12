from bisect import bisect_left, bisect_right

array = {}
reversed_array = {}

def count_by_range(a, left_value, right_value):
    right_index = bisect_right(a, right_value)
    left_index = bisect_left(a,left_value)
    return right_index - left_index

def solution(words, queries):
    answer = [0] * len(queries)
    for word in words:
        if not len(word) in array.keys():
            array[len(word)] = [word]
        else:
            array[len(word)].append(word)
        
        if not len(word) in array.keys():
            reversed_array[len(word)] = [word[::-1]]
        else:
            reversed_array[len(word)].append(word[::-1])

    for key, value in array:
        array[key] = sorted(value)
    
    for key, value in reversed_array:
        reversed_array[key] = sorted(value)

    for query in queries:
        if query[0] != "?":
            answer.append(count_by_range(array[len(query)], query.replace("?","a"),query.replace("?","z")))
        else:
            answer.append(count_by_range(reversed_array[len(query)], query.replace("?","a"), query.replace("?","z")))

    return answer
