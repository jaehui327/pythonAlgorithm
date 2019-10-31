#include <iostream>
using namespace std;

void isPerfect(int num) {
    int i, d, sum = 0;
    for(i = 1; i < num; i++) {
        d = num % i;
        if (d == 0) sum += i;
    }
    if (sum == num) cout << num << "은 완전수입니다." << endl;
    else if (sum > num) cout << num << "은 과잉수입니다." << endl;
    else cout << num << "은 부족수입니다." << endl;
}

int main() {
    int num;
    while(1) {
        cout << "자연수를 입력해주세요: ";
        cin >> num;
        if (num <= 0) break;
        isPerfect(num);
    }
    return 0;
}


