#include <iostream>
using namespace std;
long long d[201][201];
long long mod = 1000000000;
int main() {
    int n, k;
    cin >> n >> k;
    d[0][0] = 1LL;
    for (int i=1; i<=k; i++) {
        for (int j=0; j<=n; j++) {
            for (int l=0; l<=j; l++) {
                d[i][j] += d[i-1][j-l];
                d[i][j] %= mod;
            }
        }
    }
    cout << d[k][n] << '\n';
    return 0;
}

// 뭐가 틀린걸까 .. 
// #include <iostream>
// using namespace std;
// long long mod = 1000000000;

// int main() {
//     // d[k][n] = 0부터 n까지의 정수 k개를 더해서 그 합이 n이 되는 경우의 수
//     // 합 = n, 항의 개수 = k
//     int n, k;
//     cin >> n >> k;

//     // long long d[k+1][n+1];
//     long long d[201][201];
//     d[0][0] = 1LL;
    
//     for(int i=1; i<=k; i++) {
//         for(int j =0; j<=n; j++) {
//             for (int l=0; l<=j; l++) {
//                 // 모든 경우의 수를 sum하기 위해 변수 l 사용
//                 d[i][j] += d[i-1][j-l];
//                 d[i][j] %= mod;
//             }
//         }
//     }
//     cout << d[k][n] << '\n';
//     return 0;
// }