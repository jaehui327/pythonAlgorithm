#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

const int maxb = 4;
const int N = 15000;

class bitskey
{
private:
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
	node* l, * r;
	node(bitskey i) { key = i; }
};

class Dict
{
private:
	bitskey itemMin;
	struct node* head, * z;
public:
	Dict() {
		itemMin = 0;
		z = new node(itemMin);
		head = new node(itemMin);
		head->l = z;
		head->r = z;
	}

	~Dict() {
		if (z) delete z;
		if (head) delete head;
	}
	void insert(bitskey v);
	bitskey search(bitskey v);
	void check(bitskey v);
};

bitskey Dict::search(bitskey v)
{
	struct node* x;
	x = head;
	int b = maxb;
	z->key = v;
	while (v.get() != x->key.get()) {
		if (v.bits(b--, 1)) x = x->r;
		else x = x->l;
	}
	return x->key;
}

void Dict::check(bitskey v) {
	struct node* x;
	x = head;
	bitskey parent_key = x->key;
	int b = maxb;
	z->key = v;
	while (v.get() != x->key.get()) {
		parent_key = x->key;
		if (v.bits(b--, 1)) x = x->r;
		else x = x->l;
	}
	cout << "key : " << v.get();
	cout << ", parent: " << parent_key.get() << endl;
}

void Dict::insert(bitskey v)
{
	if (head->key.get() == 0) {
		head->key = v;
		return;
	}
	struct node* p, * x;
	int b = maxb;
	x = head;
	p = z;
	while (x->key.get() != z->key.get()) {
		p = x;
		if (v.bits(b--, 1)) x = x->r;
		else x = x->l;
	}
	x = new node(itemMin);
	x->key = v; x->l = z; x->r = z;
	if (v.bits(b + 1, 1)) p->r = x;
	else p->l = x;
}

void init(int key[], int search_key[])
{
	int
		i, index, temp[N + 1];
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
//    int key[N + 1] = { 0, 1, 19, 5, 18, 3, 26, 9 };
//    int search_key[N + 1] = { 0, 1, 3, 5, 9, 18, 19, 26 };
    int key[N + 1] = {};
    int search_key[N + 1] = {};

    reverse(search_key, search_key + N);
    
     init(key, search_key);
	for (i = 1; i <= N; i++) {
		bitskey tmp;
		tmp = key[i];
		d.insert(tmp);
	}

    /*
	cout << "[";
	for (i = 1; i < N + 1; i++) {
		if (i == N)
			cout << key[i] << ']' << endl;
		else
			cout << key[i] << ", ";
	}
     */
    
	start_time = clock();
	for (i = 1; i <= N; i++) {
		bitskey search_tmp;
		search_tmp = search_key[i];
		// d.search(search_tmp);
//        d.check(search_tmp);
	}
//    cout << "Execution time of digital search tree (N = " << N << ") : " <<
    cout << "Execution time of digital search tree (N = " << N << ") (reverse) : " <<
    clock() - start_time << endl;
    cout << "Search completed." << endl;
	return 0;
}
