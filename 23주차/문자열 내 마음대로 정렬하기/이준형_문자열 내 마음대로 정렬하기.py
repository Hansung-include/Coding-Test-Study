def solution(strings, n):
    answer = []
    strings_dict = {}

    for s in strings:
        if s[n] not in strings_dict:
            strings_dict[s[n]] = [s]
        else:
            strings_dict[s[n]].append(s)  # 중복되면 리스트로 추가한다

    for s, string in strings_dict.items():
        if len(string) == 1:
            continue
        strings_dict[s] = sorted(strings_dict[s])  # 오름차순으로 정렬

    indexs = strings_dict.keys()
    indexs = sorted(indexs)

    for i in indexs:
        answer.extend(strings_dict[i])  # 학습

    return answer