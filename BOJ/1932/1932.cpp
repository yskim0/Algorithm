#include <iostream>
using namespace std;
long long d[501][501];
long long a[501][501];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    
    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=i; j++) {
            cin >> a[i][j];
        }
    }

    d[0][0] = 0;
    for(int i = 1; i<=n; i++) {
        for (int j = 1; j<=i; j++) {
            d[i][j] = max(d[i-1][j], d[i-1][j-1]) + a[i][j];
        }
    }

    long long ans = d[n][1];
    for(int i = 1; i<=n; i++){
        if (ans < d[n][i]) ans = d[n][i];
    }

    cout << ans << '\n';
}