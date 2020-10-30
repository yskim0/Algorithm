#include <iostream>
using namespace std;
const long long mod = 1000000000LL;
const int limit = 100;
int main()
{
    // d[i][j] = 길이가 i이고 마지막 자리가 j인 계단 수
    // d[i][j] = d[i-1][j-1] + d[i-1][j-1]
    // j=0이나 9일 때 잘 고려해야 함 -1 또는 10이 되어 계단 수가 아니게 될 수 있어서

    int d[limit + 1][10];

    int n;
    cin >> n;

    for (int i = 1; i <= 9; i++)
        d[1][i] = 1;

    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            d[i][j] = 0;
            if(j-1 >= 0) d[i][j] += d[i-1][j-1];
            if(j+1 <= 9) d[i][j] += d[i-1][j+1];
            
            d[i][j] %= mod;
        }
    }
    long long ans = 0;
    for (int i = 0; i<=9; i++) ans += d[n][i]; 
    ans%=mod;
    cout << ans << '\n';
}