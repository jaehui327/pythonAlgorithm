def solution(k, room_number):
    answer = []
    for i in room_number:
        temp = i
        if not answer: answer.append(temp)
        else:
            for j in answer:
                if temp != j:
                    answer.append(temp)
                    break
                else:
                    temp += 1

    return answer

k = 10
room_number = [1,3,4,1,3,1]
print(solution(k, room_number))