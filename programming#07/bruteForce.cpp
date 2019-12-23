#include <iostream>
#include <string>

using namespace std;
int M = 6,N = 28;
int cnt = 0;
int bruteForce(string p, string t) {
    int i = 0, j = 0;
    for (i = 0, j = 0; j < M and i < N; i++, j++) {
        cnt++;
        if (t[i] != p[j]) {
            i = i - j;
            j = -1;
        }
    }
    if (j == M) { return i - M; }
    else { return i; }
}

int main() {
    string s = "ababacabcbababcacacbcaababca";
    string p = "ababca";
    int t=0;
    string temp = s;
    int d = 0;
    while (1) {
        t = bruteForce(p, temp);
        cout << "패턴이 나타난 위치: " << t+d << endl;
        d += t+1;
        if (d+M >= N)
            break;
        temp = s.substr(d);
        //cout << temp << endl;
    }
    cout <<"총 비교횟수 : "<<cnt<<endl;
}

