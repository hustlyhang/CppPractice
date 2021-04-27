/*
 * @lc app=leetcode.cn id=368 lang=cpp
 *
 * [368] 最大整除子集
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> largestDivisibleSubset(vector<int> &nums) {
        // 1,2,3,4,6,12
        int len = nums.size();
        if (len == 1)
            return nums;
        sort(nums.begin(), nums.end());
        vector<int> dp(len + 1, 1);
        int m = 0, pos = 1;
        for (int i = 1; i <= len; ++i) {
            for (int j = i - 1; j > 0; --j) {
                if (nums[i - 1] % nums[j - 1] == 0) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    if (dp[i] > m) {
                        m = dp[i];
                        pos = i;
                    }
                }
            }
        }
        vector<int> ans;
        // for (auto x : dp)
        //     cout << x << endl;

        int l = pos;
        // cout << "l = " << l << endl;
        ans.push_back(nums[l - 1]);
        while (l != 0) {
            int j = l - 1;
            for (; j >= 1; --j) {
                if (dp[j] == dp[l] - 1 && nums[l - 1] % nums[j - 1] == 0) {
                    l = j;
                    ans.push_back(nums[j - 1]);
                    break;
                }
            }
            l = j;
            // cout << "l = " << l << endl;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums{1, 2, 2, 4, 4, 4};
    for (auto x : s.largestDivisibleSubset(nums)) {
        cout << x << endl;
    }

    return 0;
}
// @lc code=end
