import sys

# 34452 KB, 164 ms
# 로프의 길이가 가장 긴 순서대로 나열을 해서 하나씩 뽑아 비교하면서, 최대 값을 갱신한다
# 어짜피 전체를 보는건데, 나열을 할 필요가 없어보임.

N = int(sys.stdin.readline())
rope = []
for _ in range(N):
    rope.append(int(sys.stdin.readline()))

rope = sorted(rope, reverse=True)

answer = 0

for i, r in enumerate(rope):
    answer = max(answer, (i+1) * r)

print(answer)
