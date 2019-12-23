#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;
const int d = 32;
const int q = 33554393;

int index(char c) {
    if (c == 32)
        return 0;
    else
        return c - 64;
}

int RK(char *p, int M, char *t, int N) {
    int i;
    int dM = 1;
    int h1, h2, H1;
    int cnt = 0;
    h2 = h1 = H1 = 0;
    for (i = 1; i < M; i++)
        dM = (d * dM) % q;
    for (i = 0; i < M; i++) {
        h1 = (h1 * d + index(p[i])) % q;
        h2 = (h2 * d + index(t[i])) % q;
    }
    H1 = h1;
    cout << "h1 = " << h1 << endl;
    cout << "h2 = " << h2 << endl;
    for (i = 0; h1 != h2; i++) {
        cnt++;
        h2 = (h2 + d * q - index(t[i]) * dM) % q;
        h2 = (h2 * d + index(t[i + M])) % q;
        cout << "h2 = " << h2 << endl;
        if (i > N - M)
            return N;
    }
    cout << "총 비교 : " << cnt << endl;
    return i;
}

int main() {
    char original[128] = "STRING STARTING CONSISTING";
    char pattern[128] = "STING";
    cout << "패턴이 나타난 위치 : " << RK(pattern, strlen(pattern), original, strlen(original)) << endl;
    cout << "스트링 탐색 종료" << endl;
    return 0;
    
}
