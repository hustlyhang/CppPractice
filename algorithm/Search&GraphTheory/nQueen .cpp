#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

#define SEC

const int N = 20;
int n;
char g[N][N];
bool row[N], col[N], dg[N], udg[N];

#ifdef ONE
void dfs(int k) {
    if (k == n) {
        for (int i = 0; i < n; ++i) {
            puts((const char*)g[i]);
        }
        puts("");
        return;
    }
    for (int j = 0; j < n ; j ++) {
        if (!col[j] && !dg[k + j] && !udg[n - k + j]) {
            g[k][j] = 'Q';
            col[j] = dg[k + j] = udg[n - k + j] = true;
            dfs(k + 1);
            col[j] = dg[k + j] = udg[n - k + j] = false;
            g[k][j] = '.';
        }
    }
}
#endif // ONE

#ifdef SEC
void dfs(int x, int y, int s) {
    if (y == n) y = 0, x++;
    if (x == n) {
        if (s == n) {
            for (int i = 0; i < n; ++i) {
                puts((const char*)g[i]);
            }
            puts("");
        }
        return;
    }

    // 不放皇后
    dfs(x, y + 1, s);
    // 放皇后
    if (!row[x] && !col[y] && !dg[x + y] && !udg[x - y + n]) {
        g[x][y] = 'Q';
        row[x] = col[y] = dg[x + y] = udg[x - y + n] = true;
        dfs(x, y + 1, s + 1);
        row[x] = col[y] = dg[x + y] = udg[x - y + n] = false;
        g[x][y] = '.';
    }
}

#endif // SEC




int main() {
    cin>>n;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            g[i][j] = '.';
        }
    }
#ifdef SEC
    dfs(0, 0, 0);
#endif
#ifdef ONE
    dfs(0);
#endif // ONE

    return 0;
}



/*
朝着一个方向的对角线，斜率相同，但是截距不同，并且截距唯一。
所以可以用截距作为下标来代表一条唯一的对角线。

对于斜率位 1 的对角线：
y = x + b -> b = y - x 因为y - x可能为负数，+n偏移量。因为对角线数组为2(n + 1)，所以不会越界。
对于斜率为-1的对角线：
y = -x + b -> b = y + x， x + y <= 2n

*/