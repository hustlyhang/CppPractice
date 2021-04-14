#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int main() {
    int n = 0, m = 0;

    cin>>n>>m;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; ++i) {
        cin>>nums[i];
    }

    long long ret = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            //! 异或操作优先级小于比较运算符
            if ((nums[i] ^ nums[j]) > m) {
                ret++;
            }
        }
    }


    cout<<ret;

    return 0;
}