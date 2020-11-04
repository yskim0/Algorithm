#include <iostream>
using namespace std;
bool broken[10];

int possible(int c) { // 고장난 버튼이 있는지 확인. 숫자 버튼 몇 번 눌러야 하는지 확인
    if (c == 0) {
        if (broken[0]) {
            return 0;
        } else {
            return 1;
        }
    }
    int len = 0;
    while (c > 0) {
        if (broken[c % 10]) {
            return 0; 
        }
        len += 1;
        c /= 10;
    }
    return len;
}
int main() {
    int n;
    cin >> n;
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        broken[x] = true;
    }
    // +,- 만으로 정답을 구하는 경우로 미리 셋팅
    int ans = n - 100; 
    if (ans < 0) {
        ans = -ans;
    }

    for (int i = 0; i <= 1000000; i++) {
        int c = i;
        int len = possible(c); // 숫자 버튼 횟수
        if (len > 0) {
            int press = c - n; // +나 -버튼을 몇 번 눌러야 하는지 계산
            if (press < 0) {
                press = -press;
            }
            if (ans > len + press) {
                ans = len + press;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}