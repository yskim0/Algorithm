#include <iostream>
using namespace std;

int main() {
    int t; cin >> t;
    long long d[t+1][3];
    // d[i][j] = 세로로 N칸인 우리. j=0 아무것도 없음. j=1 왼쪽에 있음. j=2 오른쪽에 있음.

    d[1][0] = 1;
    d[1][1] = 1;
    d[1][2] = 1;

    for (int i = 2; i<=t; i++) {
        d[i][0] = d[i-1][0] + d[i-1][1] + d[i-1][2];
        d[i][1] = d[i-1][0] + d[i-1][2];
        d[i][2] = d[i-1][0] + d[i-1][1];

        d[i][0] %= 9901;
        d[i][1] %= 9901;
        d[i][2] %= 9901;
    }

    cout << (d[t][0] + d[t][1] + d[t][2])%9901 << '\n';
}