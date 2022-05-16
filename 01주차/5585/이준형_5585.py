# 30864 KB / 72 ms
# 이름: 이준형
# 언어: python
# 문제 번호: 5585

import sys
price = int(sys.stdin.readline())
change = 1000 - price
money_list = [500, 100, 50, 10, 5, 1]
answer = 0
# 가격이 높은 동전순으로 최대한 바꾸자!!(그리디)
for money in money_list:
    money_num = change // money  # 최대한 바꿀수 있는 만큼 동전의 개수를 구한다.
    if money_num:  # 바꿀수 있는 동전의 개수가 1개 이상일 경우
        answer += money_num
        change -= money * money_num


print(answer)