#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int d[n]; // memo 배열
    // d[2] 는 나누어 풀 수 있는 문제다. 즉 최소 문제가 아님!!! (틀린 부분)
    d[0] = 1;
    d[1] = 1;
    for (int i=2; i<=n; i++){
        d[i] = d[i-1] + d[i-2];
        d[i] %= 10007;
    }
    cout << d[n] << '\n';
    return 0;
}