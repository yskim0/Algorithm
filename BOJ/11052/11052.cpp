#include <iostream>
using namespace std;

int main() {
    int t;
    cin.tie(nullptr);
    cin >> t;
    int d[1001]; int p[1001];
    d[0] = 0; 
    
    // p_i 
    for(int i = 1; i<=t; i++) {
        cin >> p[i];
    }

    // DP
    for(int i = 1; i<=t; i++) {
        for(int j = 1; j<=i; j++) {
            d[i] = max(d[i], d[i-j]+p[j]); // 카드 i-j개가 들어있는 카드팩을 구매하고 카드 j개를 구매
        }
    }

    cout << d[t] << '\n';
    return 0;
}