#include <iostream>
using namespace std;

int main() {
    int t; cin >> t;
    int d[t+1];
    d[0] = 0;
    for(int i = 1; i<=t; i++){
        d[i] = i; // 제곱수들의 합 나타날 때 항의 최대 개수임
        for(int j = 1; j*j<=i; j++) {
            if (d[i] > d[i-j*j] + 1)
                d[i] = d[i-j*j] + 1;
        }
    }
    cout << d[t] << '\n';
}