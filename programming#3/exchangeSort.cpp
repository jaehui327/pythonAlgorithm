#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

const int N = 5000;

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



void exchangeSort(int a[], int n){
    int i, j;
    for (i = 1; i < n + 1; i++) {
        for(j = i + 1; j < n + 1; j++) {
            if (a[i] > a[j]) swap(a, i, j);
        }
    }
}






int main()
{
    int i, a[N+1];
    double start_time;
    srand(time(NULL));
    for (i = 1; i <= N; i++) a[i] = rand();
    reverse(a, a+N);
    start_time = clock();
    exchangeSort(a, N);
    cout << "교환 정렬의 실행 시간 (N = " << N << ") : " <<
    clock() - start_time << endl;
    CheckSort(a, N);
}


