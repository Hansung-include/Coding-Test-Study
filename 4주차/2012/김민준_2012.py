N = int(input())
list = [int(input()) for _ in range(N)]

list.sort()

result = 0
for i in range(N):
    result += abs(list[i]-(i+1))

print(result)
