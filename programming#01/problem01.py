# 이진 탐색을 수행하는 함수
# a[mid] = key인 인덱스 mid를 반환하는 함수
def binarySearch(a, key, left, right):
    # 전역변수 times를 사용한다고 명시
    global times
    while left <= right:
        mid = (left + right) // 2
        if key == a[mid]:
            times += 1
            return mid
        elif key < a[mid]:
            times += 1
            return binarySearch(a, key, left, mid - 1)
        else:
            times += 1
            return binarySearch(a, key, mid + 1, right)
    # key 값이 존재하지 않으면 -1을 반환
    return -1

# 이동 횟수를 저장하는 times
times = 0
# 임의로 정수 리스트 생성
a = [0, 1, 3, 5, 6, 8, 9, 10, 12, 14, 17, 20]
# 정수 리스트 출력
print(a)
# 찾을 숫자를 입력 받는 key
key = int(input("key 값을 입력하세요: "))
# binarySearch 함수의 리턴값인 인덱스를 res에 저장, 인덱스는 0부터 len(a) - 1까지
res = binarySearch(a, key, 0, len(a) - 1)

print("------------------------------")
print("탐색 횟수 : ", times)
if res == -1:
    print("존재하지 않는 숫자입니다.")
else:
    print("key 값의 index: ", res)
