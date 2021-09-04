/*
其实是动态规划
更新的时候是
d[i, j] = min(d[i][j], d[i][k] + d[k][j])
- todo
*/


/*
输入格式
第一行包含三个整数 n,m,k。

接下来 m 行，每行包含三个整数 x,y,z，表示存在一条从点 x 到点 y 的有向边，边长为 z。

接下来 k 行，每行包含两个整数 x,y，表示询问点 x 到点 y 的最短距离。

输出格式
共 k 行，每行输出一个整数，表示询问的结果，若询问两点间不存在路径，则输出 impossible。

数据范围
1≤n≤200,
1≤k≤n2
1≤m≤20000,
图中涉及边长绝对值均不超过 10000。

*/
// 可以处理负权边，但是不能有负权环

#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 210, INF = 1e9;

int n, m, Q;
int d[N][N];

void floyd() {
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}


int main() {
    scanf("%d%d%d", &n, &m, &Q);

    // 初始化，清理自环
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == j) d[i][j] = 0;
            else d[i][j] = INF;
        }
    }
    // 清理重边
    while (m --) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        d[a][b] = min(d[a][b], c);
    }

    floyd();

    while (Q --) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (d[a][b] > INF / 2) printf("impasible\n");
        else printf("%d\n", d[a][b]);
    }
    return 0;
}