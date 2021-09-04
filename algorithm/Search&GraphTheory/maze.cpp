#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;
typedef pair<int, int> PII;

const int N = 110;
int n, m;
int g[N][N];
int d[N][N];    // 存储到起点的距离

PII q[N * N];


// 用数组模拟栈
int bfs() {
    memset(d, -1, sizeof d);
    int hh = 0,tt = 0;

    // 先放入一个节点
    q[tt++] = {0, 0};
    d[0][0] = 0;

    int dx[4] = {0, -1, 0, 1}, dy[4] = {1, 0, -1, 0};
    while (hh != tt) {
        auto k = q[hh++];
        for (int i = 0; i < 4; ++i) {
            int x = dx[i] + k.first, y = dy[i] + k.second;
            if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 && d[x][y] == -1) {
                q[tt++] = {x, y};
                d[x][y] = d[k.first][k.second] + 1;
            }
        }
    }
    return d[n - 1][m - 1];
}


int main() {
    cin>>n>>m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> g[i][j];
        }
    }
    cout<<bfs()<<endl;
}