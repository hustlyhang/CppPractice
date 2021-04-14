#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <set>
using namespace std;


/*
 * 求最大连通分量 超内存
 * 第一行为总共的行数
 * 每一行有两个名字，代表其之间有联系
 * 满足每一个人的需求，且使得分组最小
*/
void dfs(string start, unordered_map<string, vector<string>>& m, set<string>& s2) {
    for (auto s : m[start]) {
        if (s2.find(s) == s2.end()) {
            s2.insert(s);
            dfs(s, m, s2);
        }
    }
}

int main() {
    //set<string> s1;
    set<string> s2;
    unordered_map<string, vector<string>> m;
    int n = 0;
    cin>>n;
    string s;
    string t;
    while (n--) {
        cin >> s;
        cin >> t;
        //s1.insert(s);
        //s1.insert(t);
        m[s].push_back(t);
    }
    int ret =0;
    for (auto w : m) {
        if (s2.find(w.first) == s2.end()) {
            dfs(w.first, m, s2);
            ret++;
        }
    }
    cout<<ret;
    return 0;
}