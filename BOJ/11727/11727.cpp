#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int d[n];
    d[0] = 1;
    d[1] = 1;
    for (int i = 2; i<=n; i++){
        d[i] = 2*d[i-2] + d[i-1]; // 2x2타일을 사용할 경우 d[i-2]임. 가로 쓰는 거니까
        d[i] = d[i]%10007; 
    }
    cout << d[n] << '\n';
    return 0;
}