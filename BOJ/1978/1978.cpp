#include <iostream>

using namespace std;

bool prime(int n) {
    if (n<2) return false;
    for (int i = 2; i*i<=n; i++) {
        if (n%i == 0) return false;
    }
    return true;
}

int main() {
    int cnt = 0;
    int t; cin >> t;
    while(t--) {
        int num; 
        cin >> num;
        if (prime(num)) {
            cnt += 1;
        }
    }
    cout << cnt << '\n';
    return 0;
}