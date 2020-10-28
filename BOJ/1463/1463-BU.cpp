#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int d[n];
    d[1] = 0; // 구할 수 없는 건 먼저 처리
    for (int i = 2; i<=n; i++){
        // 연산의 우선순위를 생각해보았을 때 3으로 나누고 -> 안되면 2로 나누고 .. 가 더 효율적
        // 근데 그렇게 하면 10의 경우 10 -> 5 -> 4 -> 2 -> 1 이 나옴. (optimal : 10 -> 9 -> 3 -> 1)
        // 이와 같은 상황들에 적용시키기 위해서 ..?
        d[i] = d[i-1] + 1; // 1을 뺀 경우
        if (i%2==0 && d[i] > d[i/2] + 1) { // 2로 나누어 떨어지는 경우, 1을 뺀 경우보다 2로 나누는 게 연산 사용 횟수가 더 최소라면
            d[i] = d[i/2] + 1;
        }
        if (i%3==0 && d[i] > d[i/3] + 1) { // 3으로 나누어 떨어지는 경우
            d[i] = d[i/3] + 1;
        }
        
    }
    cout << d[n] << '\n';
}