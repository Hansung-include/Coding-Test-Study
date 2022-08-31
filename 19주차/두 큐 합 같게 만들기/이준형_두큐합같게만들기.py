from collections import deque

# q1, q2를 하나씩 꺼내어 두 큐의 합을 같게 만든다.
def solution(queue1, queue2):
    answer = 0
    queue1, queue2 = deque(queue1), deque(queue2)
    total_length = len(queue1) + len(queue2)

    sum_queue1 = sum(queue1)
    sum_queue2 = sum(queue2)
    sum_half = (sum_queue1 + sum_queue2) // 2

    for _ in range(total_length):
        if sum_queue2 == sum_half:
            break

        if sum_queue2 > sum_half:  # q2 가 half 보다 클때
            queue2_pop = queue2.popleft()  # q2에서 큐를 하나 꺼낸다
            queue1.append(queue2_pop)  # q1에 넣고
            sum_queue2 -= queue2_pop  # sum 값도 바꿔준다

        elif sum_queue2 < sum_half:  # q1 이 half 보다 클때
            queue1_pop = queue1.popleft()  # q1에서 큐를 하나 꺼낸다
            queue2.append(queue1_pop)  # q2에 넣고
            sum_queue2 += queue1_pop  # sum 값도 바꿔준다

        answer += 1

    if sum_queue2 != sum_half:
        answer = -1

    return answer


if __name__ == '__main__':
    print(solution([1, 1, 1, 8, 10, 9], [1, 1, 1, 1, 1, 1]))