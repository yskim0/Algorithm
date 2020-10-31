#include <iostream>
using namespace std;

int d[1001];
int a[1001];

int main() {
    int n; cin >> n;

    for(int i=1; i<=n; i++) {
        cin >> a[i];
    }
    
    // i=1부터 구하면 d[j] (j>i)는 구할 수 없음.
    // i는 뒤에서 부터 구해야 함.
    for(int i = n; i>=1; i--) {
        d[i] = 1;
        for(int j = i+1; j<=n; j++) {
            if(a[i] > a[j] && d[i] < d[j]+1)
                d[i] = d[j]+1;
        }
    }

    int ans = d[1];
    for (int i = 2; i<=n; i++) {
        if(ans < d[i]) ans = d[i];
    }

    cout << ans << '\n';
    return 0;
}