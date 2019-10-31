#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

const int N = 1000;

const int TRUE = 1;
const int FALSE = 0;
inline void swap(int a[], int i, int j)
{
    int t = a[i]; a[i] = a[j]; a[j] = t;
}
void CheckSort(int a[], int n)
{
    int i, Sorted;
    Sorted = TRUE;
    for (i = 1; i < n; i++) {
        if (a[i] > a[i+1]) Sorted = FALSE;
        if (!Sorted) break;
    }
    if (Sorted) cout << "정렬 완료." << endl;
    else cout << "정렬 오류 발생." << endl;
}

void InsertionSort(int a[], int N)
{
    int i, j, v;
    for (i = 2; i <= N; i++) {
        v = a[i]; j = i;
        while (a[j-1] > v) {
            a[j] = a[j-1]; j--;
        }
        a[j] = v;
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
    InsertionSort(a, N);
    cout << "삽입 정렬의 실행 시간 (N = " << N << ") : " <<
    clock() - start_time << endl;
    CheckSort(a, N);
}
