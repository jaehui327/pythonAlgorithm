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

void cocktailShaker(int a[], int n) {
    int i, j, k;
    for(i = 0; i < n;) {
        for(j = i + 1; j < n; j++) {
            if(a[j + 1] < a[j])
                swap(a, j + 1, j);
        }
        n--;
        for(k = n - 1; k > i; k--) {
            if(a[k + 1] < a[k])
                swap(a, k + 1, k);
        }
        i++;
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
    cocktailShaker(a, N);
    cout << "칵테일 쉐이커 정렬의 실행 시간 (N = " << N << ") : " <<
    clock() - start_time << endl;
    CheckSort(a, N);
}

