#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;






int main() {
    int n = 0;
    cin>>n;
    map<int, int> m;
    vector<int> nums(n, 0);
    stack<int> s1, s2;
    for (int i = 0; i < n; ++i) {
        cin>>nums[i];
        m[nums[i]]++;
    }
    int ret = 0;
    m[nums[0]]--;
    s1.push(nums[0]);
    s2.push(nums[1]);
    m[nums[1]]--;
    for (int i = 1; i < n; ++i) {
        if (nums[i] == s1.top() ||nums[i] == s2.top()) {
            ret++;
            continue;
        }
        if (m[s1.top()] > m[s2.top()])
        {
            s2.push(nums[i]);
            m[nums[i]]--;
        }
        else {
            s1.push(nums[i]);
            m[nums[i]]--;
        }
    }

    cout<<ret<<endl;





    return 0;
}