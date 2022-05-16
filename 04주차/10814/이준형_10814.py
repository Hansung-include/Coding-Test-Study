import sys

# sort 해줄때 나이순으로 오름차순 정렬을 하면 된다.
# 문제 조건에서 나이가 같을 경우는 먼저 가입한 순을 우선으로 했음으로 다른 추가적인 정렬을 할 필요는 없다.

N = int(sys.stdin.readline())
members = []
for _ in range(N):
    age, name = sys.stdin.readline().split()
    age = int(age)
    members.append([age, name])

members = sorted(members, key=lambda x: x[0])  # lambda 를 이용하여 제일 첫번째 원소만을 정렬함.
for age, name in members:
    print(age, name)