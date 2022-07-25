def solution(numbers, hand):
    answer = ''
    left_index = [3, 0]
    right_index = [3, 2]
    for n in numbers:
        # 왼쪽 손가락
        if n in [1, 4, 7]:
            left_index = [[1, 4, 7].index(n), 0]  # list.index 로 값을 통해 리스트에서 몇번째 인덱스인지 추출한다.
            answer += 'L'  # 문자열은 + 로 추가한다
        # 오른쪽 손가락
        elif n in [3, 6, 9]:
            right_index = [[3, 6, 9].index(n), 2]
            answer += 'R'
        # 왼쪽 손가락? 오른쪽 손가락?
        elif n in [2, 5, 8, 0]:
            n_index = [[2, 5, 8, 0].index(n), 1]
            # 어디가 더 가까운지 거리를 측정한다
            diff_l = abs(left_index[0] - n_index[0]) + abs(left_index[1] - n_index[1])
            diff_r = abs(right_index[0] - n_index[0]) + abs(right_index[1] - n_index[1])

            # 오른쪽 손가락이 더 가깝다면
            if diff_l > diff_r:
                right_index = n_index
                answer += 'R'
            elif diff_l < diff_r:
                left_index = n_index
                answer += 'L'
            else:
                # 거리가 양손 손가락이 동일하다면
                if hand == 'right':
                    # 오른손 잡이면
                    right_index = n_index
                    answer += 'R'
                else:
                    # 왼손 잡이면
                    left_index = n_index
                    answer += 'L'

    return answer