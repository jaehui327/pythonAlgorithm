#include <stdio.h>
#include <iostream>
#include <cstring>

using namespace std;
int next2[100];
int cnt = 0;

void initNext(char p[], int m) {
    int i, j;
    next2[0] = -1;
    for (i = 0, j = -1; i < m; i++, j++) {
        if (j != 1 and p[i] == p[j]) { next2[i] = next2[j]; }
        else { next2[i] = j; }
        while ((j >= 0) && (p[i] != p[j])) { j = next2[j]; }
    }
}

int KMP(char p[], char t[]) {
    int M = strlen(p);
    int N = strlen(t);
    int i, j;
    initNext(p, M);
    for (i = 0, j = 0;j < M and i < N;i++, j++) {
        if (t[i] == p[j]) cnt++;
        else {
            while (j >= 0 and t[i] != p[j]) {
                cnt++;
                j = next2[j];
            }
        }
    }
    if (j == M)
        return i - M;
    else
        return i;
}

int main() {
    char t[] = "ababacabcbababcacacaababca";
    char p[] = "ababca";
    int q, d = 0;
    while (true) {
        q = KMP(p, t + d);
        d += q;
        cout << "패턴이 나타난 위치 : " << d << endl;
        d += strlen(p);
        if (d >= strlen(t))
            break;
    }
    cout << "비교횟수 : " << cnt << endl;
    return 0;
}


