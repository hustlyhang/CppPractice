#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <vector>
#include <queue>
using namespace std;


int main(){
    int n = 0;
    cin>>n;
    string s;
    vector<int> nums;
    unordered_map<int, unordered_set<int>> m;
    getline(cin, s);
    while (getline(cin, s)) {
        int tmp = 0;
        for (auto c : s) {
            if ( c != ',') {
                tmp*=10;
                tmp+=c-'0';
            }
            else {
                nums.push_back(tmp);
                tmp = 0;
            }
        }
        nums.push_back(tmp);
        // for (auto x : nums) cout<<x<<endl;
        for (int i = 1; i < nums.size(); ++i) {
            m[nums[i]].insert(nums[0]);
        }
        nums.clear();
    }
    unordered_set<int> ret;
    int cn = 0;
    queue<int> q;
    for (auto d : m[n]) {
        q.push(d);
        ret.insert(d);
    }

    while (!q.empty()) {
        int tm = q.front();
        q.pop();
        for (auto d : m[tm]) {
            if (ret.find(d) == ret.end()) {
                q.push(d);
                ret.insert(d);
            }
        }
    }
    int nu = 0;
    for (auto d : ret) nu+=d;
    if (nu == 0) cout<<-1;
    else cout<<nu;



    return 0;
}