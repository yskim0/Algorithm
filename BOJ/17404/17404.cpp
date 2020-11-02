#include <iostream>
#include <algorithm>
using namespace std;
long long d[1001][3];
long long a[1001][3];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    long long ans = 1000*1000+1;
    for (int k = 0; k <= 2; k++) // house1's color
    { 
        for (int j = 0; j <= 2; j++)
        {
            if (j == k) // 1번 집을 정해놓고 칠한다
                d[1][j] = a[1][j];
            else
                d[1][j] = 1000 * 1000 + 1;
        }
        for (int i = 2; i <= n; i++)
        {
            d[i][0] = min(d[i - 1][1], d[i - 1][2]) + a[i][0];
            d[i][1] = min(d[i - 1][0], d[i - 1][2]) + a[i][1];
            d[i][2] = min(d[i - 1][0], d[i - 1][1]) + a[i][2];
        }
        for (int j = 0; j<=2; j++) {
            if (j==k) continue;
            ans = min(ans, d[n][j]); // 다른 색으로 칠했을 때와 비용 비교
        }
    }

    cout << ans << '\n';
}