#include <iostream>
using namespace std;

int go(int sum, int goal) {
    if(sum > goal) return 0; // 불가능한 경우 : 재귀 호출을 계속 해도 정답을 절대 찾을 수 없는 경우, 문제의 조건을 위배하는 경우
    if(sum == goal) return 1; // 정답을 찾은 경우
    int now = 0;
    for(int i =1; i<=3; i++) {
        // now += go(count + 1, sum + i, goal); // count가 의미 없어 보임
        now += go(sum + i, goal); 
    }
    return now;
}
int main() {
    int t; cin >> t;
    while(t--) {
        int goal; cin >> goal;
        cout << go(0, goal) <<'\n';
    }
    return 0;
}