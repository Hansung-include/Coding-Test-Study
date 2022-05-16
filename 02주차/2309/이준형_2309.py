# 일곱 난쟁이

# 이름: 이준형
# 언어: python
# 문제 링크: https://www.acmicpc.net/problem/2309

# 9명의 난쟁이들중 2명씩 지워 합이 100이 되는 경우의 수를 찾자!
def find_dwarf(dwarf_list):
    for i in range(len(dwarf_list)):
        for j in range(i+1, len(dwarf_list)):
            total_height = sum(dwarf_list) - dwarf_list[i] - dwarf_list[j]

            if total_height == 100:
                # 가짜 두명의 난쟁이들을 리스트에서 없앤다.
                n1, n2 = dwarf_list[i], dwarf_list[j]
                dwarf_list.remove(n1)
                dwarf_list.remove(n2)
                dwarf_list.sort()
                return dwarf_list


my_list = []
for i in range(9):
    my_list.append(int(input()))

my_list = find_dwarf(my_list)
for i in range(7):
    print(my_list[i])
