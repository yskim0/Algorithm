#include <iostream>
using namespace std;
const int MAX = 100;
int gcd(int a, int b)
{
    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; // test case 개수
    cin >> n;
    int arr[MAX];
    int m;

    while (n--)
    {
        cin >> m; // 세부 test case 개수
        long long sum = 0; // int로 하니까 틀림.
        for (int i = 0; i < m; i++)
        {
            cin >> arr[i];
        }
        // ex. m = 4
        for (int i = 0; i < m - 1; i++)
        {
            for (int j = i + 1; j < m; j++)
            {
                sum += gcd(arr[i], arr[j]);
            }
        }
        cout << sum << '\n';
    }
    return 0;
}