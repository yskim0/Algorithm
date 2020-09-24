#include <iostream>
#include <string>
#include <stack>
using namespace std;

// 괄호가 올바르게 쌍을 지었으면 YES 리턴. 아니면 NO 리턴.
string valid(string s) {
    int cnt = 0;
    for (int i=0; i<s.size(); i++) {
        // 괄호 개수로 판단할 것임. => cnt 
        if (s[i] == '('){ // 여는 괄호면 cnt 증가
            cnt += 1;
        } else { // 닫힌 괄호면 cnt 감소
            cnt -= 1;
        }
        if (cnt < 0){ // 여는 괄호가 부족
            return "NO";
        }
    }
    if (cnt == 0){ // 쌍이 맞음
        return "YES";
    } else // 닫힌 괄호가 부족
    {
        return "NO";
    }
    
} 


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;

    while (t--) {
        string s;
        cin >> s;
        cout << valid(s) << '\n';
    }
    return 0;
}