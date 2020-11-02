#include <iostream>
using namespace std;
long long d[100001];
long long s[100001];

int main() {
    int n; cin >> n;
    d[0] = 1; s[0] = 1;
    d[1] = 2; s[1] = d[0]+d[1];
    for (int i = 2; i<=n; i++){
        d[i] = d[i-1] + 2*s[i-2];
        s[i] = s[i-1] + d[i];
        d[i] %= 9901;
        s[i] %= 9901;
    }

    cout << s[n] << '\n';
}