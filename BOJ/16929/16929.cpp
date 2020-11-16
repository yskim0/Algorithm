#include <iostream>
#include <cstring>
using namespace std;
char a[55][55];
bool check[55][55];
int dist[55][55];
int n, m;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

bool go(int x, int y, int cnt, char color) {
    if (check[x][y]) return cnt-dist[x][y] >= 4;
    check[x][y] = true;
    dist[x][y] = cnt;
    for(int i = 0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < n && 0 <= ny && ny < m) {
            if(a[nx][ny] == color) {
                if (go(nx,ny, cnt+1, color)) return true;
            }
        }
    }
    return false;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i<n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<m; j++) {
            if(check[i][j]) continue;
            memset(dist, 0, sizeof(dist));
            bool ok = go(i,j,1,a[i][j]);
            if(ok) {
                cout << "Yes" << '\n';
                return 0;
            }
        }
    }
    cout << "No" << '\n';
    return 0;
}