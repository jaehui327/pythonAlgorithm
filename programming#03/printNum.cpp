#include <iostream>
#include <math.h>
using namespace std;

void printNum(int num) {
    int i, square = 0;
    for (i = 1; i < num + 1; i++) {
        if (i == pow(2, square)) {
            if (i != 1) cout << endl;
            square++;
        }
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    int num;
    while(1) {
        cout << "자연수를 입력해주세요: ";
        cin >> num;
        if (num <= 0) break;
        printNum(num);
    }
    return 0;
}




