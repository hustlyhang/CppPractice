#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    int n = 0, m = 0;
    cin>>n>>m;

    vector<string> nums;

    for (long i = 1; i <= n; ++i) {
        nums.push_back(to_string(i));
    }
    sort(nums.begin(), nums.end());

    long ret = 0;
    int len = nums[m-1].size();
    len--;
    for (auto c : nums[m-1]) {
        ret += (c - '0') * pow(10, len--);
    }

    cout<<ret;



    return 0;
}