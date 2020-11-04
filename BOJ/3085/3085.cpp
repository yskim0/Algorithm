#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int check(vector<string> &a)
{
    int n = a.size();
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        int cnt = 1;
        for (int j = 1; j < n; j++) // i행에 대해
        {
            if (a[i][j] == a[i][j - 1])
            {
                cnt += 1;
            }
            else {
                cnt = 1;
            }
            if (ans < cnt)
                ans = cnt;
        }
        cnt = 1;
        for(int j=1; j<n; j++) { // i열에 대해
            if(a[j][i] == a[j-1][i]) {
                cnt += 1;
            } else {
                cnt = 1;
            }
            if (ans < cnt) ans = cnt;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            if (j + 1 < n)
            {                               // 열이 넘어가지 않으면
                swap(a[i][j], a[i][j + 1]); // 왼쪽 오른쪽 스왑
                int temp = check(a);
                if (ans < temp)
                    ans = temp;
                swap(a[i][j], a[i][j + 1]); // 다시 제자리로
            }

            if (i + 1 < n)
            {                               // 행이 넘지 않으면
                swap(a[i][j], a[i + 1][j]); // 위 아래 스왑
                int temp = check(a);
                if (ans < temp)
                    ans = temp;
                swap(a[i][j], a[i + 1][j]);
            }
        }
    }
    cout << ans << '\n';
    return 0;
}