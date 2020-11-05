#include <iostream>
using namespace std;
int a[10];

// index 라는 수를 결과에 O/X 할지 결정하는 함수
// index : 자연수
// selected : 지금까지 선택한 수의 개수
void go(int index, int selected, int n, int m) 
{
    if (selected == m) // 정답 구한 것
    {
        for (int i = 0; i < m; i++)
        {
            cout << a[i];
            if (i != m - 1)
                cout << ' ';
        }
        cout << '\n';
        return;
    }
    if (index > n) return;
    // index를 결과에 추가하는 경우
    a[selected] = index;
    go(index+1, selected+1, n, m);
    //index를 결과에 추가하지 않는 경우
    a[selected] = 0;
    go(index+1, selected,n,m);
}

int main() {
    int n, m;
    cin >> n >> m;
    go(1, 0, n, m);
    return 0;
}