#include <iostream>
using namespace std;
const int MAX = 1000000;
int prime[MAX];
int pn;
bool check[MAX+1];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 에라토스테네스의 체
    for (int i=2; i<=MAX; i++) {
        if(check[i] == false) { // prime
            prime[++pn] = i;
            for (int j = i+i; j<=MAX; j+=i) {
                check[j] = true; // remove
            }
        }
    }

    // 2보다 큰 모든 짝수는 두 소수의 합으로 표현이 가능하다.
    while(true) {
        int n;
        cin >> n;
        if (n==0) {
            break;
        }
        for (int i = 1; i< pn; i++) {
            if(check[n-prime[i]] == false) {
                cout << n << " = " << prime[i] << " + " << n- prime[i] << '\n';
                break;
            }
        }

    }
    
    return 0;
}