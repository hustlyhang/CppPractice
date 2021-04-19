#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

struct Node{
    int t, i, k;
    Node(int _t, int _i, int _k):t(_t),i(_i),k(_k){};
};

struct cmp
{
    bool operator()(Node& a, Node& b){
        if (a.t == b.t) return a.i > b.i;
        else return a.t > b.t;
    }
};


priority_queue<Node, vector<Node>, cmp> q;

int main(){
    vector<int> ans;
    int n = 0, m = 0;
    cin>>n>>m;
    for (int i = 0; i < n; ++i) {
        int t = 0;
        cin>>t;
        q.push(Node(t,i,1));
    }

    for (int i = 0; i < m; ++i) {
        auto tmp = q.top();

        ans.push_back(tmp.i + 1);
        q.pop();
        q.push(Node((tmp.t/tmp.k) * (tmp.k + 1), tmp.i, tmp.k + 1));
    }

    for (int i = 0; i < ans.size(); ++i) {
        cout<<ans[i];
        if (i != ans.size() - 1) cout<<endl;
    }




    return 0;

}