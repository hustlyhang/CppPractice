#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
unordered_map<char, string> um;
int ans;
void dfs(string& p, string& s, int i, int j){
    if (i == p.size() && j == s.size()) {
        ans++;
        return;
    }
    if (i == p.size() || j == s.size()) {
        return;
    }

    if (um.find(p[i]) != um.end()) {
        int len = um[p[i]].size();
        if (um[p[i]] == s.substr(j, len)) {
            dfs(p, s, i + 1, j + len);
        }
        else return;
    }
    else {
        for (int k = j + 1; k < s.size(); ++k) {
            um.insert({p[i], s.substr(j, k - j)});
            dfs(p, s, i + 1, k);
            um.erase(p[i]);
        }
    }
}



int main(){
    string p, s;
    cin>>p;
    cin>>s;
    dfs(p, s, 0, 0);
    cout<<ans;




    return 0;
}