#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <algorithm>
using namespace std;

pair<int, int> tmp;

static bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) return a.second < b.second;
    else return a.first < b.first;
}


bool isdigit(pair<int,int>& a, pair<int, int>& b) {
    if ((a.first == 0 && a.second == 0) || (b.first == 0 && b.second == 0)) return false;
    if (a.first == 0 && b.first == 0) return false;
    if (a.second == 0 && b.second == 0) return false;
    if (a.first == b.first) return false;
    if (a.first < b.first && a.second < b.second) return false;
    if (a.first > b.first && a.second > b.second) return false;

    int x = 0, y = 0;
    bool flgx = false, flgy = false;
    if ((b.first * a.second - a.first * b.second)%(b.second - a.second) == 0) {
        y = (b.first * a.second - a.first * b.second)/(b.second - a.second);
        flgy = true;
    }
    if(flgy && a.first == 0) {
        if ((y - b.second) % b.first == 0) {
            
            x = (y - b.second) / b.first;
            flgx = true;
        }
    }
    if(flgy && b.first == 0) {
        if ((y - a.second) % a.first == 0) {
            x = (y - a.second) / a.first;
            flgx = true;
        }
    }
    tmp.first = x;
    tmp.second = y;
    if (flgx && flgy) return true;
    else return false;
}




int main() {
    int n = 0;
    cin>>n;
    vector<pair<int, int>> nums(n);
    for (int i = 0; i < n; ++i) {
        cin>>nums[i].first>>nums[i].second;
    }
    sort(nums.begin(), nums.end(), cmp);

    map<pair<int, int>,set<int>> m;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (isdigit(nums[i], nums[j])) {
                m[tmp].insert(i);
                m[tmp].insert(j);
            }
        }
    }

    vector<int> ret(n, 0);
    for (auto c : m) {
        ret[c.second.size()]++;
    }
    for (int i = 2; i <= ret.size(); ++i) {
        cout<<ret[i];
        if (i != ret.size()) cout<<' ';
    }

    return 0;
}