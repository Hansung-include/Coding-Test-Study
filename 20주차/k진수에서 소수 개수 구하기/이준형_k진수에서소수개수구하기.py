
import math

def is_prime(n):
    ''' 소수인지 알려주는 함수 '''
    for i in range(2, int(math.sqrt(n))+1):
        if n%i == 0:
            return False
    return True

def change_k_num(n, k):
    ''' k 진법으로 바꿔주는 함수 리턴값:문자열 '''
    num = ''
    while n:
        num = str(n%k) + num
        n = n//k
    return num


def solution(n, k):
    answer = 0
    change_n = change_k_num(n, k)  # k진법으로 바꾸기
    check = ''
    for i, c in enumerate(change_n):

        if c != '0':
            check += c  # 조건에 맞는 숫자 찾기
            if i != len(change_n)-1:
                continue
        if len(check):
            check = int(check)
            if check > 1:
                if is_prime(check):  # 소수인지 체크
                    answer += 1  # 맞다면 개수 추가
            check = ''
    return answer


if __name__ == '__main__':
    print(solution(437674, 3))
    print(solution(110011, 10))