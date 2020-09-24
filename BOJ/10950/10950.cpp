#include <iostream>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, a, b;
    cin >> t;
    while(t--){
        cin >> a >> b;
        cout << a+b << '\n';
    }
    return 0;


}
