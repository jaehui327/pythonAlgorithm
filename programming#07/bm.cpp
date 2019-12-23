#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstring>

int skip[27];
int cnt;
void initSkip(char* p) {
    int m = strlen(p);
    for (int i = m; i >= 0; i--) {
        for (int j = 'A'; j <= 'Z'; j++) {
            if (p[i] == j) skip[j - 'A'] = i;
        }
    }
    for (int i = 0; i < 26; i++)
        if (skip[i] == -1) skip[i] = m;
}

int index(char a) {
    for (int i = 'A'; i <= 'Z'; i++)
        if (i == a) return i - 'A';
    return 0;
}

int BM(char* p, char* t) {
    int i, j;
    int m = strlen(p);
    int n = strlen(t);
    initSkip(p);
    for (i = m - 1, j = m - 1; j >= 0; i--, j--) {
        cnt++;
        while (t[i] != p[j]) {
            cnt++;
            int k = skip[index(t[i])];
            if (m - j > k) i = i + m - j;
            else i = i + k;
            if (i >= n) return n;
            j = m - 1;
        }
        cnt++;
    }
    return i + 1;
}

int main() {
    char text[] = "STRING STARTING CONSISTING";
    char pattern[] = "STING";
    for (int i = 0; i < 26; i++)
        skip[i] = -1;
    int n = BM(pattern, text);
    printf("%d %d", n, cnt);
}
