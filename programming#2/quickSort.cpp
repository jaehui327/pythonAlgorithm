#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

const int N = 25000;
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

void QuickSort(int a[], int l, int r) {
    int i, j, v;
    if (r > l) {
        v = a[r]; i = l-1; j = r;
        for ( ; ; ) {
            while (a[++i] < v);
            while (a[--j] > v);
            if (i >= j) break;
            swap(a, i, j);
        }
        swap(a, i, r);
        QuickSort(a, l, i-1);
        QuickSort(a, i+1, r);
    }
}

int main()
{
    int i, a[N+1];
    double start_time;
    a[0] = -1; // 감시 키
    srand(time(NULL));
    for (i = 1; i <= N; i++) a[i] = rand();
    reverse(a, a+N);
    start_time = clock();
    QuickSort(a, 1, N);
    cout << "퀵 정렬의 실행 시간 (N = " << N << ") : " <<
    clock() - start_time << endl;
    CheckSort(a, N);
}
