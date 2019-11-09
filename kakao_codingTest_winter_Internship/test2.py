def solution(s):
    answer = []
    strList = []
    numList = []
    list = []
    # 문자열 분할해서 리스트 저장
    l = s.split(",{")
    for i in l:
        a = i.replace("{", "")
        b = a.replace("}", "")
        strList.append(b)
    # 크기순 정렬
    strList.sort(key=len)
    # 숫자로 변환
    for i in strList:
        numList = i.split(",")
        numList = [int (a) for a in numList]
        list.append(numList)

    # 리스트가 0이 될때까지
    while(1):
        if not list: break
        # 맨 앞 리스트만 확인
        num = list[0][0]
        # 정답에 넣음
        answer.append(num)
        list.pop(0)

        # 리스트 순회
        for j in list:
            # 리스트 내의 숫자 순회
            for k in range(0, len(j)):
                if num == j[k]:
                    j.pop(k)
                    break
    return answer

#s = "{{2},{2,1},{2,1,3},{2,1,3,4}}"
#s = "{{20,111},{111}}"
s = "{{4,2,3},{3},{2,3,4,1},{2,3}}"
print(solution(s))