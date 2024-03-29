#include <iostream>
#include "geo.h"
int N = 12;
using namespace std;

void swap(struct point a[], int i, int j) {
    struct point t = a[i]; a[i] = a[j]; a[j] = t;
}

int ccw(struct point p0, struct point p1, struct point p2) {
    int dx1, dx2, dy1, dy2;
    dx1 = p1.x - p0.x;
    dy1 = p1.y - p0.y;
    dx2 = p2.x - p0.x;
    dy2 = p2.y - p0.y;
    if (dx1 * dy2 > dy1 * dx2) return +1;
    if (dx1 * dy2 < dy1 * dx2) return -1;
    if ((dx1 == 0) && (dy1 == 0)) return 0;
    if ((dx1 * dx2 < 0) || (dy1 * dy2 < 0)) return -1;
    if ((dx1 * dx1 + dy1 * dy1) < (dx2 * dx2 + dy2 * dy2)) return +1;
    return 0;
}

float theta(struct point p1, struct point p2) {
    int dx, dy, ax, ay;
    float t;
    dx = p2.x - p1.x; ax = abs(dx);
    dy = p2.y - p1.y; ay = abs(dy);
    t = (ax + ay == 0) ? 0 : (float)dy / (ax + ay);
    if (dx < 0) t = 2 - t; else if (dy < 0) t = 4 + t;
    return t * 90.0;
}

void SelectionSort(struct point p[], int N) {
    int i, j, min;
    for (i = 1; i < N; i++) {
        min = i;
        for (j = i + 1; j <= N; j++)
            if (theta(p[1], p[j]) < theta(p[1], p[min])) {
                 cout << p[min-1].c <<'-'<<p[j-1].c <<'-'<<p[j].c<<endl;
                min = j;
            }
        swap(p, min, i);
    }
}

int GrahamScan(point p[], int N) {
    int i, min, M;
    for (min = 1, i = 2; i <= N; i++)
        if (p[i].y < p[min].y) min = i;
    for (i = 1; i <= N; i++)
        if (p[i].y == p[min].y)
            if (p[i].x > p[min].x) min = i;
    swap(p, 1, min);
    SelectionSort(p, N);
    for(int q=1;q<=N;q++)
        cout << p[q].c <<' ';
    cout << endl;
    p[0] = p[N];
    for (M = 3, i = 4; i <= N; i++) {
        while (ccw(p[M], p[M - 1], p[i]) >= 0) {
            cout << p[M-1].c <<'-'<<p[M].c <<'-'<<p[i].c<<endl;
            M--;
        }
        M++; swap(p, i, M);
    }
    return M;
}

int main() {
    struct point p[N + 1];
    int i, M;
    for (i = 1; i <= N; i++) {
        p[i].x = x_value[i - 1];
        p[i].y = y_value[i - 1];
        p[i].c = c_value[i - 1];
    }
    M = GrahamScan(p, N);
     for (i = 1; i <= M; i++)
         cout << p[i].c << " ";
     cout << endl;
}

