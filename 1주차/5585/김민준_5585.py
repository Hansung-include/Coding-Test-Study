MONEY = 1000  # 문제에서 주어진 낸 돈 상수로 선언
changes = [500, 100, 50, 10, 5, 1]  # 거스름돈 종류 내림차순으로 리스트 선언

payment = int(input())
money = MONEY - payment

cnt = 0

for i in changes:
    cnt += money // i  # 제일 큰 종류부터 몫을 cnt에 더해주고
    money %= i  # 나머지

print(cnt)
