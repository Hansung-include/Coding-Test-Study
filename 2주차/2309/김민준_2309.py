N = 9
SUM = 100

heights = [int(input()) for _ in range(9)]

flag = False
for i in range(N):
    for j in range(i+1, N):
        tmp = sum(heights) - (heights[i] + heights[j])
        # 두 값을 뽑아서 list의 합계에서 빼줬을때 100이 되면 된다.
        if tmp == SUM:
            h1 = heights[i]
            h2 = heights[j]

heights.remove(h1)
heights.remove(h2)
heights.sort()

print(*heights, sep='\n')
