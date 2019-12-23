#include <iostream>
#include <cstring>
using namespace std;

const int TRUE = 1;
const int FALSE = 0;
class PQ{
private:
    int* heap, * info;
    int n;
public:
    PQ(int size = 100) {
        heap = new int[size];
        info = new int[size];
        n = 0;
    }
    ~PQ() { delete heap; }
    void insert(int v, int x);
    int remove();
    int isEmpty() { if (n == 0) return TRUE; else return FALSE; }
};
void PQ::insert(int v, int x) {
    int i;
    n++;
    for (i = n; ; ) {
        if (i == 1) break;
        if (v >= heap[i / 2]) break;
        heap[i] = heap[i / 2];
        info[i] = info[i / 2];
        i /= 2;
    }
    heap[i] = v;
    info[i] = x;
}
int PQ::remove() {
    int i, j, x, v, temp_v, temp_x;
    x = info[1];
    temp_v = heap[n];
    temp_x = info[n];
    n--;
    i = 1;
    j = 2;
    while (j <= n) {
        if (j < n && heap[j] > heap[j + 1]) j++;
        if (temp_v <= heap[j]) break;
        heap[i] = heap[j];
        info[i] = info[j];
        i = j;
        j *= 2;
    }
    heap[i] = temp_v;
    info[i] = temp_x;
    return x;
}
int index(char c) {
    if (c == 32) return 0;
    else return (c - 64);
}
void decode(int dad[],int count[], int len[],char s[],int M) {
    int k=43,i;
    int p=0;
    char q,c;
    while(1) {
        c=s[p++];
        if(c == '1')
            k=-k;
        for (i=0;i<M;i++) {
            if(dad[i] == k)
                break;
        }
        k=i;
        if(k < 23) {
            q = k+64;
            cout << q;
            break;
        }
    }
}
int main(){
    char text[100] = "A SIMPLE STRING TO BE ENCODED USING A MINIMAL NUMBER OF BITS";
    int count[100], dad[100], len[27], code[27];
    PQ pq(100);
    int i, j, k, t, t1, t2, x, M = strlen(text), cnt = 0;
    for (i = 0; i < 100; i++) {
        count[i] = 0;
        dad[i] = 0;
    }
    for (i = 0; i < M; i++) count[index(text[i])]++;
    for (i = 0; i <= 26; i++)
        if (count[i]) pq.insert(count[i], i);
    for (; !pq.isEmpty(); i++) {
        t1 = pq.remove(); t2 = pq.remove();
        dad[i] = 0; dad[t1] = i; dad[t2] = -i;
        count[i] = count[t1] + count[t2];
        if (!pq.isEmpty()) pq.insert(count[i], i);
    }
    int tmp=i;
    for (k = 0; k <= 26; k++) {
        i = 0; x = 0; j = 1;
        if (count[k])
            for (t = dad[k]; t; t = dad[t], j += j, i++)
                if (t < 0) {
                    x += j; t = -t;
                }
        code[k] = x; len[k] = i;
    }
    //과제 구현 부분
    /*
    for (int i = 0; i < 26; i++) // 2-1번, 2-3번
     {
     if(count[i] != 0)
         cout << "k=" <<i<< ", count[k]=" << count[i]<<' ' << endl;
         /*
     if(count[i] !=0)
     {
     cout <<"k="<<i<<", code[k]="<<code[i]<<", length[k]="<<len[i]<<", binary value=";
     for (int j = len[i]; j > 0; j--)
     cout << ((code[i] >> j - 1) & 1);
     cout << endl;
     }
     
     }
*/
    char s[10];
    // 3번
    
    cout << "디코드 할 값(2진수)을 입력해주세요 :";
    cin >> s;
    decode(dad,count,len,s,M);
    
    /*
     for(int i=0;i < tmp;i++)//2-2번
     {
     if(count[i] != 0)
     cout << "k="<<i<<", count[k]="<<count[i]<<", dad[k]="<<dad[i]<<endl;
     }
     */
    /*for (j = 0; j <= M; j++) {
     for (i = len[index(text[j])]; i > 0; i--) {
     cout << ((code[index(text[j])] >> i - 1) & 1);
     cnt++;
     if (cnt % 50 == 0) cout << endl;
     }
     }*/
    cout << endl;
}

