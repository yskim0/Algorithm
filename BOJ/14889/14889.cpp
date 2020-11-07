#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int s[20][20];
int n;
int go(int index, vector<int> &first, vector<int> &second) {
    if(index ==n) {
        // 제외시키는 경우
        if (first.size() != n/2) return -1;
        if (second.size() != n/2) return -1;
        int t1= 0; // 1번 팀의 능력치
        int t2=0; // 2번 팀의 능력치
        // 모든 쌍에 대해서 팀의 능력치 구함
        for(int i =0; i<n/2; i++) {
            for(int j =0; j<n/2; j++) {
                if (i==j) continue;
                t1 += s[first[i]][first[j]];
                t2 += s[second[i]][second[j]];
            }
        }
        // 차이
        int diff = t1-t2;
        if (diff <0) diff = -diff;
        return diff;
    }
    // 다음을 호출해야 하는 경우
    int ans = -1;
    // 1번 팀에 넣는 경우
    first.push_back(index);
    int t1 = go(index+1, first, second);
    if (ans == -1 || (t1 != -1 && ans > t1)) ans = t1;
    first.pop_back();
    // 2번 팀에 넣는 경우
    second.push_back(index);
    int t2 = go(index+1, first, second);
    if(ans == -1 || (t2 != -1 && ans > t2)) ans = t2;
    second.pop_back();
    return ans;
}

int main() {
    cin >> n;
    for(int i =0; i<n; i++) {
        for(int j = 0; j<n; j++){
            cin >> s[i][j];
        }
    }
    vector<int> first, second;
    cout << go(0,first, second) << '\n';
}