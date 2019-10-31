#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

const int N = 25000;

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

int a[N + 1];
int b[N + 1];
int run[N + 1];

void merge(int a[], int l, int m, int r) {
    int i, j, k;
    for (i = m+1; i > l; i--) b[i-1] = a[i-1];
    for (j = m; j < r; j++) b[r+m-j] = a[j+1];
    for (k = l; k <= r; k++) a[k] = (b[i] < b[j]) ? b[i++] : b[j--];
}

int makeRun(int a[], int run[]) {
    int i = 1, j = 1;
    for (i = 1; i <= N; i++) {
        if (a[i] > a[i+1]) {
            run[j++] = i;
        }
    }
    return j - 1;
}

int moveRun(int run[], int cnt)
{
    int i, j = 1;
    for (i = 2; i <= cnt; i += 2) run[j++] = run[i];
    if ((cnt % 2) != 0) run[j] = run[i - 1];
    else j--;
    return j;
}

void naturalMergeSort(int a[], int n){
    int i, num;
    int cnt;
    
    run[0] = 0;
    cnt = makeRun(a, run);
    while (cnt > 1) {
        if ((cnt % 2) != 0) num = cnt - 1;
        else num =  cnt;
        for (i = 1; i <= num; i += 2)
            merge(a, run[i - 1] + 1, run[i], run[i + 1]);
        cnt = moveRun(run, cnt);
    }
}


int main() {
    int i, a[N+1];
    double start_time;
    srand(time(NULL));
    for (i = 1; i <= N; i++) a[i] = rand();
//    reverse(a, a+N);
    start_time = clock();
    naturalMergeSort(a, N);
    cout << "자연 합병 정렬의 실행 시간 (N = " << N << ") : " <<
    clock() - start_time << endl;
    CheckSort(a, N);
}

