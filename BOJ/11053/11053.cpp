#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
    int t; cin >> t;
    vector<int> a(t+1);
    vector<int> d(t+1);
    for (int i = 1; i<=t; i++) cin >> a[i];

    for(int i=1; i<=t; i++) {
        d[i] = 1; // 우선 길이 1로 초기화
        // 자신보다 전에 있던 element들 접근
        for(int j=1; j<i; j++) { 
            // 자신보다 작고, 증가하고 있는 길이가 가장 클 수 있다면... 
            if (a[j] < a[i] && d[i] < d[j]+1)
                d[i] = d[j]+1;
        }
    }
    // d[t]가 LIS가 아님. max가 뭔지 차례대로 다 둘러봐야하는데 벡터 사용시 메서드 사용 가능
    cout << *max_element(d.begin(), d.end()) << '\n';
}