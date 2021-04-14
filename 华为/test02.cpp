#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <queue>
using namespace std;

priority_queue<int> q;


/*
    * 解答错误？ 每一次新增的可以开始的作业是按照序号来完成还是按照可以开始的时间来排序
    * 输入：第一行代表每个作业的时间 第二行代表每个作业的依赖关系，必须要依赖的作业完成后才能开始
    * 0->2 代表2号作业完成后，0号作业才能开始做
    * 输出每个作业完成的时间
*/


void dfs(vector<int> &t, unordered_map<int, set<int>> m,vector<int>& ret, int start, int& ti, vector<int> times) {
    if (t[start] == 0) {
        for (auto c : m[start]) {
            t[c]--;
            if (t[c] == 0) q.push(c);
            dfs(t, m, ret, c, ti, times);
        }
    }
}
int main() {
    vector<int> times;
    string s1;
    string s2;
    getline(cin, s1);
    getline(cin, s2);
    unordered_map<int, set<int>> m;
    int sum = 0;
    for (auto c : s1) {
        if (c >= '0' && c <= '9') {
            sum*=10;
            sum+=c-'0';
        }
        else {
            times.push_back(sum);
            sum = 0;
        }
    }
    if (sum) times.push_back(sum);
    vector<int> t(times.size(), 0); // 存放每个位置出度
    vector<int> ret(times.size(), 0);
    bool firstnumber = false;
    bool secondnumber = true;
    sum = 0;
    int f = 0;
    int se = 0;
    for (auto c : s2) {
        if (firstnumber == false && c >= '0' && c <= '9') {
            sum*=10;
            sum += c - '0';
        }
        else if (c == '-') {
            f = sum;
            sum = 0;
            firstnumber = true;
            secondnumber = false;
            t[f]++;
        }
        else if (c == '>') {
            continue;
        }
        else if (secondnumber == false && c >= '0' && c <= '9') {
            sum*=10;
            sum += c - '0';
        }
        else if (c == ',') {
            se = sum;
            sum = 0;
            firstnumber = false;
            secondnumber = true;
            m[se].insert(f);
        }
    }
    m[sum].insert(f);

    int ti = 0;
    for (int i = 0; i < times.size(); ++i) {
        if (t[i] == 0) {
            ti+=times[i];
            ret[i] = ti;
            dfs(t, m, ret, i, ti, times);
        }
    }

    while (!q.empty()){
        int i = q.top();
        ti+= times[i];
        ret[i] = ti;
        q.pop();
        dfs(t, m, ret, i, ti, times);
    }
    for (int i = 0; i < ret.size(); ++i) {
        cout<<ret[i];
        if (i != ret.size() - 1) cout<<',';
    }
    return 0;
}