x = 0
arr1 = []
arr2 = []
arr3 = []
# 크기가 n인 정수 리스트를 만들기 위해 입력 받음
n = int(input("정수 n을 입력하세요: "))

# 사면체 수열 arr1
for i in range(1, n + 1):
    for j in range(1, i + 1):
        for k in range(1, j + 1):
          x += 1
    arr1.append(x)
# arr1 출력
print("arr1:", arr1)

# arr1의 계차수열 arr2
for i in range(1, len(arr1)):
  arr2.append(arr1[i] - arr1[i - 1])
# arr2 출력
print("arr2:", arr2)

# arr2의 계차수열 arr3
for i in range(1, len(arr2)):
  arr3.append(arr2[i] - arr2[i - 1])
# arr3 출력
print("arr3:", arr3)