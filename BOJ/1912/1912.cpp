#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    long long d[t];
    long long v[t];
    for (int i = 0; i < t; i++)
        cin >> d[i];

    for (int i = 0; i < t; i++)
    {
        //아래 2개 무조건 필요함. 안하면 쓰레기값 나옴.
        v[i] = d[i]; 
        if(i==0) continue;
        v[i] = max(v[i - 1] + d[i], d[i]);
    }
    
    // 최대값 구하기
    int max = v[0];
    for(int i = 0; i<t; i++){
        if(v[i] > max) {
            max = v[i];
        }
    }

    cout << max << '\n';
}