#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
    * 路径问题 第一行有三个数，m，n，t 分别代表 行数，列数， 以及时间
    * 接下俩会有m*n个数据，代表时间， 需要从左上走到右下， 每次只能向下或者向右
    * 输出最大的游玩时间
*/

vector<int> tmp;
int mi = -1;

void dfs(int i, int j, vector<vector<int>> time, int s, int n, int m, int t) {
    if (i == n - 1 && j == m - 1) {
        mi = max(mi, s);
    }

    if (i + 1 < n && s + time[i+1][j] <= t) {
        dfs(i + 1, j, time, s + time[i+1][j], n, m, t);
    }
    
    if (j + 1 < m && s + time[i][j + 1] <= t) {
        dfs(i, j + 1, time, s + time[i][j + 1], n, m, t);
    }
}
int main() {
    int n = 0;
    int m = 0;
    cin>>n;
    cin>>m;
    int t = 0;
    cin>>t;
    int tmp = 0;
    vector<vector<int>> time(n, vector<int>(m,0));
    for (int i = 0; i <n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin>>tmp;
            time[i][j] = tmp;
        }
    }
    dfs(0,0,time,time[0][0],n,m, t);
    cout<<mi;
    return 0;

}