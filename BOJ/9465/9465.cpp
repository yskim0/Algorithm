#include <iostream>
#include <algorithm>
using namespace std;
long long d[100001][3];
long long a[100001][2];
int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while(t--) {
        long long n; cin >> n;

        // input
        for(int i =1; i<=n; i++){
            cin >> a[i][0];
        }
        for(int i=1; i<=n; i++) {
            cin >> a[i][1];
        }

        // DP
        d[0][0] = d[0][1] = d[0][2] = 0;
        for(int i = 1; i<=n; i++) {
            d[i][0] = max(max(d[i-1][0],d[i-1][1]),d[i-1][2]); // 뜯지 않음
            d[i][1] = max(d[i-1][0], d[i-1][2]) + a[i][0]; // 위에 뜯음
            d[i][2] = max(d[i-1][0], d[i-1][1]) + a[i][1]; // 아래 뜯음
        }
        long long ans = max(max(d[n][0], d[n][1]),d[n][2]);
        cout << ans << '\n';
    }
}