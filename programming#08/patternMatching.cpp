#include <iostream>
const int scan = -1;
const int TRUE = 1;
const int FALSE = 0;
char ch[10] = { ' ', ' ', ' ', 'A', 'B', 'A', 'C', 'D', ' ',' ' };
int next1[10] = { 1,2,3,2,7,6,7,8,0,0 };
int next2[10] = { 1,5,4,2,7,6,7,8,0,0 };
using namespace std;
class Deque {
private:
    int* deque;
    int first, last;
public:
    Deque(int size = 100) {
        deque = new int[size];
        first = size / 2; last = size / 2;
        for (int i = 0; i < size; i++) deque[i] = 0;
    }
    ~Deque() { delete deque; }
    void insertFirst(int v) { deque[first--] = v; }
    void insertLast(int v) { deque[++last] = v; }
    int deleteFirst() { deque[first] = 0; return deque[++first]; }
    int isEmpty() { if (first == last) return TRUE; else return FALSE; }
    void prDq() {
        int s_first = first+1;
        int s_last = last;
        while (s_first != s_last+1) {
            if (deque[s_first] == 0) {
                s_first++;
                continue;
            }
            cout << deque[s_first++] << ' ';
        }
    }
};
int match(char* t) {
    int n1, n2;
    Deque dq(100);
    int j = 0, N = strlen(t), state = next1[0];
    
    dq.insertLast(scan);
    while (state) {
        if (state == scan) {
            j++;
            if (dq.isEmpty()) dq.insertFirst(next1[0]);
            dq.insertLast(scan);
        }
        else if (ch[state] == t[j])
            dq.insertLast(next1[state]);
        else if (ch[state] == ' ') {
            n1 = next1[state]; n2 = next2[state];
            dq.insertFirst(n1); if (n1 != n2) dq.insertFirst(n2);
        }
        dq.prDq();
        cout << endl;
        if (dq.isEmpty()) return j;
        if (j > N) return 0;
        state = dq.deleteFirst();
    }
    return j - 1;
}
int main() {
    char text[100] = "CCDA";
    int N, pos, previous = 0, i = 0;
    N = strlen(text);
    while (1) {
        pos = match(text + i);
        if (pos == 0) break;
        pos += previous;
        i = pos;
        if (i <= N) cout << "패턴이 발생한 위치 : " << pos << endl;
        else break;
        previous = i;
    }
    cout << "패턴 매칭 종료." << endl;
}
