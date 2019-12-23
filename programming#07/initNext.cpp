#include <stdio.h>
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

void initNext(string p,int m) {
    int next[100] = {};
    int i, j;
    next[0] = -1;
    for (i = 0, j = -1; i < m; i++, j++) {
        next[i] = j;
        while ((j >= 0)&&(p[i]!=p[j])) {
            j = next[j];
        }
    }
    cout << "재시작 위치 배열: ";
    for (i = 1; i < m; i++)
        cout<<next[i]<<" ";
    cout << endl;
}
int main() {
    char p1[] = "ababca";
    char p2[] = "abababca";
    char p3[] = "abcbabcbabc";
    char p4[] = "abracadabra";
    
    initNext(p1, strlen(p1));
    initNext(p2, strlen(p2));
    initNext(p3, strlen(p3));
    initNext(p4, strlen(p4));
    return 0;
}


