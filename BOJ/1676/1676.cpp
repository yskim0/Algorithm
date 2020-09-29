#include <iostream>
using namespace std;

int main() {
    int num;
    cin >> num;

    // 팩토리얼에서의 0의 개수는 5의 제곱수에 몇 개가 나눠지는지를 체크하면 된다.
    // 소인수분해 했을 때 2의 개수가 항상 크기 때문에 5만 체크하면 됨.

    int mod_5 = int(num/5);
    int mod_25 = int(num/25);
    // 25*5 = 125
    int mod_125 = int(num/125);
    // 125*5 > 500 이므로 그만.

    cout << mod_5+mod_25+mod_125 << '\n';
    return 0;

}

// #include <iostream>
// using namespace std;
// int main() {
//     int ans = 0;
//     int n;
//     cin >> n;
//     for (int i=5; i<=n; i*=5) {
//         ans += n/i;
//     }
//     cout << ans << '\n';
//     return 0;
// }