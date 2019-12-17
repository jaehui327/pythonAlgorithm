def bubbleSort(a, n):
    for i in range(1, n + 1):
        if i % 2 == 0:
            for j in range(0, n):
                if a[j] > a[j + 1]:
                    a[j], a[j + 1] = a[j + 1], a[j]
        else:
            for j in range(n - 1, 0, -1):
                if a[j] > a[j + 1]:
                    a[j], a[j + 1] = a[j + 1], a[j]
        print('i =', i, ',', a)

def checkSort(a, n):
    isSorted = True
    for i in range(1, n):
        if (a[i] > a[i + 1]):
            isSorted = False
        if (not isSorted):
            break
    if isSorted:
        print("정렬 완료")
    else:
        print("정렬 오류 발생")

import random, time

N = 10
a = [0, 7, 5, 6, 4, 10, 9, 8, 1, 3, 2]
# a.append(None)
print('a =', a)
# for i in range(N):
#     a.append(random.randint(1, N))
start_time = time.time()
bubbleSort(a, N)
end_time = time.time() - start_time
# print('버블 정렬의 실행 시간 (N = %d) : %0.3f' %(N, end_time))
checkSort(a, N)