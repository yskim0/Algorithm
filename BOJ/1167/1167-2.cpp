#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
struct Edge {
    int to;
    int cost;
    Edge(int to, int cost) : to(to), cost(cost) {
    }
};
vector<Edge> a[100001];
bool check[100001];
pair<int, int> dfs(int x) { // first: diameter, second: height
    check[x] = true;
    vector<int> heights;
    int ans = 0;
    for (auto &e : a[x]) {
        int y = e.to;
        int cost = e.cost;
        if (check[y] == false) {
            auto p = dfs(y);
            if (ans < p.first) ans = p.first;
            heights.push_back(p.second+cost);
        }
    }
    int height = 0;
    sort(heights.begin(), heights.end());
    reverse(heights.begin(), heights.end());
    if (heights.size() >= 1) {
        height = heights[0];
        if (ans < height) {
            ans = height;
        }
    }
    if (heights.size() >= 2) {
        if (ans < heights[0] + heights[1]) {
            ans = heights[0] + heights[1];
        }
    }
    return make_pair(ans, height);
}
int main() {
    int n;
    scanf("%d",&n);
    for (int i=1; i<=n; i++) {
        int x;
        scanf("%d",&x);
        while (true) {
            int y, z;
            scanf("%d",&y);
            if (y == -1) break;
            scanf("%d",&z);
            a[x].push_back(Edge(y,z));
        }
    }
    auto ans = dfs(1);
    cout << ans.first << '\n';
    return 0;
}