#include <iostream>
using namespace std;

void isPrime(int num) {
    int i, sum = 0;
    for (i = 2; i < num; i++) {
        if (num % i == 0) sum++;
    }
    if (sum == 0) cout << num << "은 소수입니다." << endl;
    else cout << num << "은 소수가 아닙니다." << endl;
}

int main() {
    int num;
    while(1) {
        cout << "자연수를 입력해주세요: ";
        cin >> num;
        if (num <= 0) break;
        isPrime(num);
    }
    return 0;
}



