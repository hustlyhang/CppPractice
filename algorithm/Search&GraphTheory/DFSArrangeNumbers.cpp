#include <iostream>
#include <cstring>
using namespace std;


/*
给定一个数字n，生成满足字典序的所有序列
*/
const int N = 10;
int n, t;
bool flg[N];
int path[N];

void dfs(int k) {
    if (k == n) {
        for (int i = 0; i < n; ++i) printf("%d ", path[i]);
        puts("");
        return;
    }
    for (int j = 1; j <= n ; j ++) {
        if (!flg[j]) {
            path[k] = j;
            flg[j] = true;
            dfs(k + 1);
            flg[j] = false;
        }
    }
}

int main() {
    memset(flg, false, sizeof flg);
    cin>>n;
    dfs(0);
}