#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> ans;



bool isEqual(string s1, string s2) {
    int len1 = s1.size();
    if (len1 % 2 == 1) return s1 == s2;
    bool flg = false;

    return (isEqual(s1.substr(0, len1/2),s2.substr(0, len1/2)) && isEqual(s1.substr(len1/2),s2.substr(len1/2)))||
            (isEqual(s1.substr(0, len1/2),s2.substr(len1/2)) && isEqual(s1.substr(len1/2),s2.substr(0, len1/2)));
}
int main(){
    int n = 0;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        string s1, s2;
        cin>>s1;
        cin>>s2;
        if (isEqual(s1, s2)) ans.push_back("YES");
        else ans.push_back("NO");
    }

    for (int i = 0; i <ans.size(); ++i) {
        cout<<ans[i];
        if (i != ans.size() - 1) cout<<endl;
    }


    return 0;

}