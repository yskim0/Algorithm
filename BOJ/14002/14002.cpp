#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int t = 1000;
vector<int> a(t + 1);
vector<int> d(t + 1);
vector<int> v(t + 1);

void go(int p) {
    if (p == -1) return ;
    go(v[p]);
    cout << a[p] << ' ';
}

int main()
{
    int n;
    cin >> n;

    
    for (int i =  0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++)
    {
        d[i] = 1; // 우선 길이 1로 초기화
        v[i] = -1;
        // 자신보다 전에 있던 element들 접근
        for (int j = 0; j < i; j++)
        {
            // 자신보다 작고, 증가하고 있는 길이가 가장 클 수 있다면...
            if (a[j] < a[i] && d[i] < d[j] + 1){
                d[i] = d[j] + 1;
                v[i] = j;
            }
        }
    }
    

    int ans = d[0];
    int p = 0;
    for (int i=0; i<n; i++) {
        if (ans < d[i]) {
            ans = d[i];
            p = i;
        }
    }

    cout << ans << '\n';
    go(p); 
    cout << '\n';

}