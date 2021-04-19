#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> ans;
bool cmp(const pair<int, int>& a,const pair<int, int>& b) {
    if (a.first == b.first) return a.second>b.second;
    else return a.first < b.first;
}

void deal(vector<pair<int, int>>& vec) {
    int ret = 0, sum = 0;
    int pos = vec[0].first;
    ret+=vec[0].second;
    sum += vec[0].second;
    for (int i = 1; i < vec.size(); ++i) {
        sum += vec[i].second;
        if (vec[i].first == pos) continue;
        else {
            pos = vec[i].first;
            ret+=vec[i].second;
        }
    }
    ans.push_back(sum - ret);
}


int main(){
    int t = 0;
    cin>>t;
    
    while (t--){
        int n = 0;
        cin>>n;
        vector<int> times(n), hnr(n);
        for (int i = 0; i < n; ++i) cin>>times[i];
        for (int i = 0; i < n; ++i) cin>>hnr[i];
        vector<pair<int, int>> vec(n);
        for (int i = 0; i < n; ++i) {
            vec[i].first = times[i];
            vec[i].second = hnr[i];
        }
        sort(vec.begin(), vec.end(), cmp);
        deal(vec);
        
    }
    for (int i = 0; i < ans.size(); ++i) {
        cout<<ans[i];
        if (i != ans.size() - 1) cout<<endl;
    }


}