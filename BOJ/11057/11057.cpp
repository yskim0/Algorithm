#include <iostream>
using namespace std;

long long d[1001][10];
long long mod = 10007;

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i <= 9; i++)
        d[1][i] = 1;

    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            for (int l = 0; l <= j; l++)
            {
                d[i][j] += d[i - 1][l];
                d[i][j] %= mod;
            }
        }
    }

    long long sum = 0;
    for (int i = 0; i <= 9; i++)
        sum += d[n][i];
    sum %= mod;
    cout << sum << '\n';
    return 0;
}