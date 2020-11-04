#include <iostream>
using namespace std;

int main() {
    int e,s,m;
    cin >> e >> s >> m;
    e -= 1;
    s -= 1;
    m -= 1;
    for (int i = 0;; i++) {
        if (i%15==e && i%28==s && i%19 == m) {
            cout << i+1 << '\n';
            break;
        }
    }
}