#include <iostream>
using namespace std;

int main() {
    cin.tie(nullptr);
    int t;
    cin >> t;
    int d[t+1]; int p[t+1]; d[0]=0;
    for(int i = 1; i<=t; i++) d[i] = -1; // min값을 구해야하기 때문에 

    for(int i = 1; i<=t; i++) cin >> p[i];
    for(int i = 1; i<=t; i++) {
        for (int j = 1; j<=i; j++) {
            if (d[i] == -1 || d[i] > d[i-j]+p[j])
                d[i] = d[i-j] + p[j];
        }
    }

    cout << d[t] << '\n';
    return 0;

}