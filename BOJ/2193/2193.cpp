#include <iostream>
using namespace std;

int main() {
    // d[i][j] = i자리 이친 수 중에서 끝 자리가 j인 개수
    // d[i][0] = d[i-1][1] + d[i-1][0]
    // d[i][1] = d[i-1][0]
    // 초기화 -> d[1][0] = 0, d[1][1] = 1;

    int n; cin >> n; 
    
    long long d[91][2]; // 큰 숫자가 들어오기 때문에 long long으로.. 이 실수 많다.
    d[1][0] = 0; d[1][1] = 1;
    for (int i = 2; i<=n; i++) {
        d[i][0] = d[i-1][0] + d[i-1][1];
        d[i][1] = d[i-1][0];
    }
    cout << d[n][0] + d[n][1] << '\n';
}