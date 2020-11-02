#include <iostream>
using namespace std;
long long d[201];
long long mod = 1000000000;
int main()
{
    int n, k;
    cin >> n >> k;
    d[0] = 1;

    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            d[j] += d[j - 1];
            d[j] %= mod;
        }
    }
    cout << d[n] << '\n';
}