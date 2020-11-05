#include <iostream>
using namespace std;
int a[10];
int cnt[10];
// index 라는 수를 결과에 O/X 할지 결정하는 함수
// index : 자연수
// selected : 지금까지 선택한 수의 개수
void go(int index, int selected, int n, int m) 
{
    if (selected == m) {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=cnt[i]; j++) {
                cout << i << ' ';
            }
        }
        cout << '\n';
        return;
    }
    if (index > n) return;

    // 선택 O
    // 몇 개 선택할지
    // 최대 ~ 1개 선택한 것까지(감소하는 순 => 전체 수열로 정렬해서 하라고 했음)
    for (int i = m-selected; i>=1; i--) { 
        cnt[index] = i; // 수 i를 몇 번 포함해야 하는지
        go(index+1, selected+i, n, m);
    }

    // 선택 X
    cnt[index] = 0;
    go(index+1, selected, n, m);
}

int main() {
    int n, m;
    cin >> n >> m;
    go(1, 0, n, m);
    return 0;
}