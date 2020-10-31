#include <iostream>
using namespace std;
long long d[1001];
long long v[1001];

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }

    for (int i = 1; i <= n; i++)
    {
        d[i] = v[i];
        for (int j = 1; j < i; j++)
        {
            if (v[j] < v[i] && d[i] < d[j] + v[i])
                d[i] = d[j] + v[i];
        }
    }

    // d[n]이 바로 정답이 될 수 없음!! LIS 류 문제에서는 이를 주의할 것
    long long ans = d[1];
    for (int i = 2; i<=n; i++) {
        if (ans < d[i]) ans = d[i];
    }

    cout << ans << '\n';
}