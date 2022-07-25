import sys


text = sys.stdin.readline().rstrip()
filter_s = sys.stdin.readline().rstrip()
length = len(filter_s)
cnt = 0
i = 0

while i < len(text):
    if text[i:i+length] == filter_s:
        cnt += 1
        i += length
    else:
        i += 1

print(cnt)
