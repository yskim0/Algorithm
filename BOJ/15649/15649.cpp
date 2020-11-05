#include <iostream>
using namespace std;
bool c[10]; 
int a[10]; // 결과를 저장하는 배열
void go(int index, int n, int m) { // index 번째를 채우려고 함
    if (index == m) {
        for (int i=0; i<m; i++) {
            cout << a[i];
            if (i != m-1) cout << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = 1; i<=n; i++) {
        if(c[i]) continue;
        // index 번째 수 i를 넣음
        c[i] = true; 
        a[index] = i;
        go(index+1, n, m); // 다음 번째
        c[i] = false; 
        a[index] = 0;// 다 만든거니까
    }

}

int main() {
    int n, m;
    cin >> n >> m;
    go(0,n,m);
}