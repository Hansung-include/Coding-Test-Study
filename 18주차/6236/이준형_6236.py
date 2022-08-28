import sys

N, M = map(int, sys.stdin.readline().split())
price_list = []
for _ in range(N):
    price_list.append(int(sys.stdin.readline()))

start = 0
end = sum(price_list)

while start <= end:
    mid = (start + end) // 2  # k: 인출금액
    cnt = 0  # 인출 횟수
    low_mid = False  # 인출 금액이 적은지 나타내는 변수
    have_price = 0  # 현재 가지고 있는 돈

    for price in price_list:
        if have_price >= price:
            have_price -= price

        else:
            cnt += 1
            have_price = mid - price
            low_mid = True if have_price < 0 else False

        if cnt > M or low_mid:  # 횟수가 초과하거나 인출 금액이 적다면
            start = mid + 1  # 금액을 높인다
            low_mid = True
            break

    if not low_mid:  # 횟수가 M보다 적거나 같고, 인출 금액이 적지 않다면
        end = mid - 1  # 최소 값을 찾기 위한 갱신
        k = mid

print(k)