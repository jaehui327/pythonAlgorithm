#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

const int N = 5000;
const int TRUE = 1;
const int FALSE = 0;

inline void swap (int a[], int i, int j) {
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
}

void CheckSort (int a[], int n) {
    int i, Sorted;
    Sorted = TRUE;
    for (i = 1; i < n; i++) {
        if (a[i] > a[i+1])
            Sorted = FALSE;
        if (!Sorted)
            break;
    }
    if (Sorted)
        cout << "정렬 완료." << endl;
    else
        cout << "정렬 오류 발생." << endl;
}



void SelectionSort(int a[], int N) {
    int i, j, min;
    for (i = 1; i < N; i++) {
        min = i;
        for (j = i + 1; j <= N; j++)
            if (a[j] < a[min])
                min = j;
        swap(a, min, i);
    }
}




int main() {
    int i, a[N + 1];
    double start_time;
    
    srand(time(NULL));
    for (i = 1; i <= N; i++)
        a[i] = rand();
    reverse(a, a+N);
    start_time = clock();
    SelectionSort(a, N);
    cout << "선택 정렬의 실행 시간 (N = " << N << ") : " << clock() - start_time << endl;
    CheckSort(a, N);
    return 0;
}
