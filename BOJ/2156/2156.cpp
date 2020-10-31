#include <iostream>
using namespace std;
long long d[10001][3];
long long a[10001];

int main() {
    int n; cin >> n;
    for(int i = 1; i<=n; i++) cin >> a[i];
    d[0][0] = d[0][1] = d[0][2] = 0;

    for(int i = 1; i<=n; i++) {
        d[i][0] = max(max(d[i-1][0],d[i-1][1]),d[i-1][2]); // 안고르는 것
        d[i][1] = d[i-1][0] + a[i];
        d[i][2] = d[i-1][1] +a[i];
    }

    cout << max(max(d[n][0], d[n][1]),d[n][2]) << '\n';
    
}