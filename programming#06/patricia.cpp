#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

const int maxb = 14;
const int N = 7;

class bitskey
{ private:
    int x;
public:
    int get() { return x; }
    bitskey& operator=(int i) { x = i; return *this; }
    unsigned bits(int k, int j) {
        return (x >> k) & ~(~0 << j);
    }
};
struct node
{
    bitskey key;
    int b;
    node *l, *r;
    node(bitskey i) { key= i; }
};
int bits(bitskey item, int bit, unsigned cmp)
{
    if (item.bits(bit,1) == cmp) return 1;
    else return 0;
}

class Dict
{ private:
    bitskey itemMin;
    struct node *head;
public:
    Dict() {
        itemMin = 0;
        head = new node(itemMin);
        head->b = maxb;
        head->l = head->r = head;
    }
    ~Dict() {
        if (head) delete head;
    }
    void insert(bitskey v);
    void check(bitskey v);
    bitskey search(bitskey v);
};

bitskey Dict::search(bitskey v)
{
    struct node *p, *x;
    p = head;
    x = head->l;
    while (p->b > x->b) {
        p = x;
        x = (bits(v,x->b,1))? x->r : x->l;
    }
    if (v.get() != x->key.get()) return itemMin;
    return x->key;
}

void Dict::check(bitskey v){
    struct node* p;
    struct node* x;
    p = head;
    x = head->l;
    bitskey parent_key = x->key;
    while (p->b > x->b) {
        p = x;
        parent_key = x->key;
        if (bits(v, x->b, 1)) x = x->r;
        else x = x->l;
    }
    cout << "key : " << v.get();
    cout << " , parent: " << parent_key.get() << endl;
}

void Dict::insert(bitskey v)
{
    struct node *p, *t, *x;
    int i = maxb;
    p = head;
    t = head->l;
    while (p->b > t->b) {
        p = t;
        t = (bits(v,t->b,1)) ? t->r : t->l;
    }
    if (v.get() == t->key.get()) return;
    while (bits(t->key, i , 1) == bits(v,i,1)) i--;
    p = head;
    x = head->l;
    while( p->b > x->b && x->b > i ) {
        p = x;
        x = ( bits(v,x->b,1) ) ? x->r : x->l;
    }
    t = new node(itemMin);
    t->key = v;
    t->b = i;
    t->l = (bits(v, t->b, 1)) ? x : t;
    t->r = (bits(v, t->b, 1)) ? t : x;
    if (bits(v,p->b,1)) p->r = t;
    else p->l = t;
}

void init(int key[], int search_key[])
{
    int i, index, temp[N+1];
    for (i = 1; i <= N; i++) {
        key[i] = i;
        search_key[i] = i;
        temp[i] = 0;
    }
    srand(time(NULL));
    for (i = 1; i <= N; i++) {
        index = rand() % N + 1;
        if (temp[index] == 0)
            temp[index] = key[i];
        else {
            while (temp[index] != 0)
                index = (index % N) + 1;
            temp[index] = key[i];
        }
    }
    for (i = 1; i <= N; i++) {
        key[i] = temp[i];
    }
}

int main()
{
    Dict d;
    int i;
    double start_time;
    // int key[N + 1], search_key[N + 1];
    int key[N + 1] = { 0, 1, 19, 5, 18, 3, 26, 9 };
    int search_key[N + 1] = { 0, 1, 3, 5, 9, 18, 19, 26 };
    // init(key, search_key);
    for (i = 1; i <= N; i++) {
        bitskey tmp;
        tmp = key[i];
        d.insert(tmp);
    }
    
    cout << "[";
    for (i = 1; i < N + 1; i++) {
        if (i == N)
            cout << key[i] << ']' << endl;
        else
            cout << key[i] << ", ";
    }
    
    start_time = clock();
    for (i = 1; i <= N; i++) {
        bitskey search_tmp;
        search_tmp = search_key[i];
        // d.search(search_tmp);
        d.check(search_tmp);
    }
    cout << "패트리샤 트리의 실행 시간 (N = " << N << ") : " <<
    clock() - start_time << endl;
    cout << "탐색 완료." << endl;
}

