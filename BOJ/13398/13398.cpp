#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> d(100001);
vector<int> d2(100001);
vector<int> a(100001);

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    // d[i] : i번째에서 끝
    for (int i = 1; i <= n; i++)
    {
        d[i] = a[i];
        if (i == 1)
            continue;
        if (d[i] < d[i - 1] + a[i])
        {
            d[i] = d[i - 1] + a[i];
        }
    }

    // d2[i] : i번째에서 시작
    for (int i = n; i >= 1; i--)
    {
        d2[i] = a[i];
        if (i == n)
            continue;
        if (d2[i] < d2[i + 1] + a[i])
        {
            d2[i] = d2[i + 1] + a[i];
        }
    }

    int ans = d[1];
    for (int i = 2; i <= n; i++)
    {
        if (ans < d[i])
        {
            ans = d[i];
        }
    }

    for (int i = 2; i <= n - 1; i++)
    {
        if (ans < d[i - 1] + d2[i + 1])
            ans = d[i - 1] + d2[i + 1];
    }

    cout << ans << '\n';
    return 0;
}