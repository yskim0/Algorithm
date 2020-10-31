#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    // input
    int t;
    cin >> t;
    long long d[t+1][3], a[t+1][3];
    for (int i = 0; i < t; i++)
    {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }

    // DP
    d[0][0] = a[0][0];
    d[0][1] = a[0][1];
    d[0][2] = a[0][2];

    // 이번 문제는 j를 안써도 된다.
    for (int i = 1; i < t; i++)
    {

        d[i][0] = min(d[i - 1][1], d[i - 1][2]) + a[i][0];
        d[i][1] = min(d[i - 1][0], d[i - 1][2]) + a[i][1];
        d[i][2] = min(d[i - 1][0], d[i - 1][1]) + a[i][2];
    }

    int max = d[t-1][0];
    for (int i = 1; i < 3; i++) {
        if(max > d[t-1][i]) max = d[t-1][i];
    }
    cout << max << '\n';
}