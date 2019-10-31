#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

const int N = 25000;

const int TRUE = 1;
const int FALSE = 0;

void CheckSort(int a[], int n) {
    int i, Sorted;
    Sorted = TRUE;
    for (i = 1; i < n; i++) {
        if (a[i] > a[i + 1]) Sorted = FALSE;
        if (!Sorted) break;
    }
    if (Sorted) cout << "정렬 완료." << endl;
    else cout << "정렬 오류 발생." << endl;
}

struct Node {
    int key;
    struct Node *left, *right;
};

struct Node *newNode(int item) {
    struct Node *temp = new Node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

void storeSorted(Node *root, int arr[], int &i){
    if (root != NULL) {
        storeSorted(root->left, arr, i);
        arr[i++] = root->key;
        storeSorted(root->right, arr, i);
    }
}

Node* insert(Node* node, int key) {
    if (node == NULL) return newNode(key);
    
    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    
    return node;
}

void treeSort(int arr[], int n) {
    struct Node *root = NULL;
    
    root = insert(root, arr[0]);
    for (int i = 1; i < n; i++)
        insert(root, arr[i]);
    int i = 0;
    storeSorted(root, arr, i);
}

int main() {
    int i, a[N+1];
    double start_time;
    srand(time(NULL));
    for (i = 1; i <= N; i++) a[i] = rand();
    reverse(a, a+N);
    start_time = clock();
    treeSort(a, N);
    cout << "토너먼트 정렬의 실행 시간 (N = " << N << ") : " <<
    clock() - start_time << endl;
}

