#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    // 입출력 속도 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // test case num.
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string str; 
        getline(cin, str); // 개행문자 \n이 나올때까지 받음
        str += '\n';
        stack<char> s;

        for (char ch : str){
            if (ch == ' ' || ch == '\n') { // 공백이거나 한 줄 띄어지면 단어 뒤집어서 출력할 것임.
                while (!s.empty()) { 
                    cout << s.top(); 
                    s.pop();
                }
                cout << ch;
            } else {
                s.push(ch); // 알파벳이니 스택에 push
            }
        }
    }
    return 0;
}