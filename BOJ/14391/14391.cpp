#include <iostream>
#include <cstdio>
using namespace std;
int a[4][4];
int main() {
    int n, m;
    scanf("%d %d",&n,&m);
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            scanf("%1d",&a[i][j]);
        }
    }
    int ans = 0;
    // 0: -, 1 : |
    for (int s= 0; s<(1<<(n*m)); s++) {
        int sum = 0;

        // 가로가 얼마나 연속되는지
        for(int i =0; i<n; i++) {
            // 가로 하나에 해당
            int cur = 0; // 누적된 가로의 수
            for (int j =0; j<m; j++) {
                int k = i*m+j;
                if((s&(1<<k))==0) {
                    cur = cur * 10 + a[i][j];
                }
                else { // 세로의 경우. 가로의 연속이 끊김
                    sum += cur;
                    cur = 0;
                }
            }
            sum += cur;
        }

        // 세로 기준
        for(int j = 0; j<m; j++) {
            int cur =0;
            for(int i=0; i<n; i++) {
                int k = i*m+j;
                if((s&(1<<k))!=0) {
                    cur = cur * 10 + a[i][j];
                }
                else {
                    sum += cur;
                    cur = 0;
                }
            }
            sum += cur;
        }
        ans = max(ans, sum);
    }
    cout << ans <<'\n';
}