def possible(answer):
    for x, y, stuff in answer:
        if stuff == 0:  # pillar
            if (
                y == 0
                or [x - 1, y, 1] in answer
                or [x, y - 1, 0] in answer
                or [x, y, 1] in answer
            ):
                continue
            return False
        else:  # roof
            if (
                [x, y - 1, 0] in answer
                or [x + 1, y - 1, 0] in answer
                or ([x - 1, y, 1] in answer and [x + 1, y, 1] in answer)
            ):
                continue
            return False
    return True


def solution(n, build_frame):
    construct = [[0] * n for _ in range(n)]

    answer = []
    for frame in build_frame:
        x, y, stuff, operate = frame
        if operate == 0:  # 삭제
            answer.remove([x, y, stuff])
            if not possible(answer):
                answer.append([x, y, stuff])
        else:  # 설치
            answer.append([x, y, stuff])
            if not possible(answer):
                answer.remove([x, y, stuff])

    return sorted(answer)
