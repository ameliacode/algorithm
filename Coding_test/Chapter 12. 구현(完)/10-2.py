def rotate_a_matrix_by_90_degree(key):
    n = len(key)
    result = [[0] * n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            result[j][n - i - 1] = key[i][j]
    return result


def check(new_lock):
    m = len(new_lock) // 3
    for i in range(m, 2 * m):
        for j in range(m, 2 * m):
            if new_lock[i][j] != 1:
                return False
    return True


def solution(key, lock):
    n = len(key)
    m = len(lock)
    new_lock = [[0] * (3 * m) for _ in range(3 * m)]

    for i in range(m, 2 * m):
        for j in range(m, 2 * m):
            new_lock[i][j] = lock[i - m][j - m]

    for _ in range(4):
        key = rotate_a_matrix_by_90_degree(key)
        for y in range(2 * m):
            for x in range(2 * m):
                for i in range(n):
                    for j in range(n):
                        new_lock[i + y][j + x] += key[i][j]
                if check(new_lock):
                    return True
                for i in range(n):
                    for j in range(n):
                        new_lock[i + y][j + x] -= key[i][j]
    return False
