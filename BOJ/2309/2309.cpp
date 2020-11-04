#include <iostream>
#include <algorithm>
using namespace std;
int a[9];
int main() {
    int sum = 0;
    for(int i = 0; i<9; i++) {
        cin >> a[i];
        sum += a[i];
    }

    sort(a,a+9); // 우선 정렬
    for(int i = 0; i<9; i++) {
        for(int j = i+1; j<9; j++) {
            if(sum-a[i]-a[j] == 100) {
                for(int k = 0; k<9; k++) {
                    if(i==k || j==k) continue; // i, j 번째가 가짜이므로
                    cout << a[k] << '\n';
                }
                return 0; // 한 가지만 구하고 종료. 이 부분 없으면 가능한 경우의 수 다 구함..
            }
        }
    }
    return 0;
}