#include <iostream>
using namespace std;
int d[1001], d2[1001], df[1001];
int a[1001];

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    // LIS
    for (int i = 1; i <= n; i++)
    {
        d[i] = 1;
        for (int j = 1; j < i; j++)
        {
            if (a[i] > a[j] && d[i] < d[j] + 1)
                d[i] = d[j] + 1;
        }
    }

    // 역 LIS
    for(int i = n; i>= 1; i--) {
        d2[i] = 1;
        for(int j = i+1; j<=n; j++) {
            if(a[i] > a[j] && d2[j]+1 > d2[i])
                d2[i] = d2[j] + 1;
        }
    }


    for(int i = 1; i<=n; i++) df[i] = d[i]+d2[i] - 1;

    int ans = df[1];
    for(int i = 2; i<=n; i++) {
        if(ans < df[i]) ans = df[i];
    }

    cout << ans << '\n'; 

}