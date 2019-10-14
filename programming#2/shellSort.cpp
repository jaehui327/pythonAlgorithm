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

void ShellSort(int a[], int N) {
    int i, j, h, v;
    for (h = 1; h < N; h = 3*h+1) ;
    for ( ; h > 0; h /= 3)
        for (i = h+1; i <= N; i++) {
            v = a[i]; j = i;
            while (j > h && a[j-h] > v) {
                a[j] = a[j-h]; j -= h;
            }
            a[j] = v;
        }
}

int main() {
    int i, a[N+1];
    double start_time;
    a[0] = -1; // 감시 키
    srand(time(NULL));
    for (i = 1; i <= N; i++) a[i] = rand();
    reverse(a, a+N);
    start_time = clock();
    ShellSort(a, N);
    cout << "쉘 정렬의 실행 시간 (N = " << N << ") : " <<
    clock() - start_time << endl;
    CheckSort(a, N);
}
