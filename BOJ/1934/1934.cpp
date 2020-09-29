#include <iostream>
using namespace std;

int gcd(int a, int b) {
    while (b!=0) {
        int r = a%b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    int a,b;
    while (t--) {
        cin >> a >> b;
        cout << a*b/gcd(a,b) << '\n';
    }
}