#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



class test{
  public:
    int numSquares(int n){
        vector<int> list;
        // 相当于有这么多个物品；
        for (int i = 1; i * i <= n; ++i) {
            list.push_back(i * i);
        }

        // 完全背包问题，
        vector<vector<int>> dp(list.size(), vector<int>(n + 1, INT_MAX/2));

        // 先考虑第一个物品，初始化
        for (int i = 0; i <= n; ++i) {
            dp[0][i] = i;
        }
        // 考虑每一个物品
        for (int i = 1; i < list.size(); ++i) {
            for (int j = list[i]; j <= n; ++j) {
                // 只有当当前背包容量大于物品重量时才能放进去
                
                dp[i][j] = min(dp[i - 1][j], dp[i][j - list[i]] + 1);
                
            }
        }
        int ret = INT_MAX;
        for (int i = 0; i < list.size(); ++i) {
            ret = min(ret, dp[i][n]);
        }
        return ret;


    }



}; 

int main(){
    test t;
    cout<<t.numSquares(5);

    return 0;
}