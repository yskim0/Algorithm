#include <iostream>
using namespace std;
bool c[10];
int a[10];

void go(int index, int start, int n, int m) {
    if (index == m) {
        for (int i=0; i<m; i++) {
            cout << a[i];
            if (i != m-1) cout << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i=start; i<=n; i++) {
        // if(c[i]) continue;
        // c[i] = true; 
        a[index] = i;
        go(index+1, i, n, m); // 같은 것이 뒤에 또 올 수 있으니 i부터...
        // c[i] = false;
        // 실제로 이 문제에서 c 배열은 아무런 의미가 없음.
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    go(0,1,n,m);
}