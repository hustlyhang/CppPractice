#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;




class Solution {
public:
    /**
     * 
     * @param matrix int整型vector<vector<>> the matrix
     * @return int整型
     */
    int minPathSum(vector<vector<int> >& matrix) {
        // write code here
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        //? 初始化
        dp[0][0] = matrix[0][0];
        for (int i = 1; i < rows; ++i) {
            dp[i][0] = matrix[i][0] + dp[i - 1][0];
        }
        for (int j = 1; j < cols; ++j) {
            dp[0][j] = matrix[0][j] + dp[0][j - 1];
        }
        for (int i = 1; i < rows; ++i) {
            for (int j = 1; j < cols; ++j) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + matrix[i][j];
            }
        }
        return dp[rows - 1][cols - 1];
    }
};