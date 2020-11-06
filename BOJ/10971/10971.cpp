#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int w[20][20];

int main() {
    int n; cin >> n;
    for(int i =0; i<n; i++) {
        for(int j = 0; j<n; j++) cin >> w[i][j];
    }
    
    vector<int> d(n); // d : 방문 순서. d[0] -> d[1] -> ... -> d[N-1] -> d[0]
    for(int i=0; i<n; i++) d[i]=i;
    
    int ans = 2147483647;
    do{
        // if (d[0] != 1) break; 첫 번째 도시가 1에서 다른 수로 변경 되었다는 것은 더이상 모든 순서를 만들 필요가 없다
        // -> O(N!)
        bool ok = true;
        int sum = 0;
        for(int i = 0; i<n-1; i++) { // 0~n-1번 도시까지 구하고 있음
            if (w[d[i]][d[i+1]] == 0) ok =false; // 갈 수 없음
            else sum += w[d[i]][d[i+1]];
        }
        if (ok && w[d[n-1]][d[0]] != 0) { // 마지막 도시에서 첫 도시로 돌아오는 거
            sum += w[d[n-1]][d[0]];
            if(ans > sum) ans = sum;
        }
    } while(next_permutation(d.begin() +1, d.end())); // O((N-1)!xN)이 된다

    cout << ans << '\n';
    return 0;
}