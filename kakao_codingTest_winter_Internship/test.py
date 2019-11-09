def solution(board, moves):
    answer = 0
    ans = []
    temp = 0
    # moves의 개수만큼 반복
    for i in moves:
        # index로 사용하기 위해 -1
        i = i - 1
        # board의 개수만큼 반복
        for j in range(0, len(board)):
            # 0이 아닌 값이 나오면 임시 값에 저장 후 반복 멈춤
            if board[j][i] != 0:
                temp = board[j][i]
                board[j][i] = 0
                # 꺼낸 항목 리스트가 비어있으면 ans에 추가
                if not ans:
                    ans.append(temp)
                    break
                # ans의 마지막 항목과 temp가 같으면 pop해주고 answer에 2 더함
                elif ans[-1] == temp:
                    ans.pop(-1)
                    answer += 2
                    break
                # 아니면 ans에 추가
                else:
                    ans.append(temp)
                    break
    return answer

board = [[0,0,0,0,0],[0,0,1,0,3],[0,2,5,0,1],[4,2,4,4,2],[3,5,1,3,1]]
moves = [1,5,3,5,1,2,1,4]
print(solution(board, moves))