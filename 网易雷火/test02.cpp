#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

struct Node{
    int t,l;
    char p;
    Node(int _t, int _l, char _p):t(_t),l(_l),p(_p){};
};
int m,n,x,y,r;
int ps,ops,que;
vector<vector<int>> pos;
vector<int> qutime;
unordered_map<int, vector<Node>> mtp;
static bool cmp(Node& a, Node& b) {
    return a.t < b.t;
}

bool isIn(int _x, int _y){
    if (_x >= x - r && _x <= x + r && _y >= y - r && _y <= y + r
        && _x >= 1 && _x <= m && _y >= 1 && _y <= n) {
            return true;
        }
    return false;
}


int main(){
    cin>>m>>n>>x>>y>>r;
    cin>>ps;
    pos.assign(ps,vector<int>(2));
    for (int i = 0; i < ps; ++i) {
        cin>>pos[i][0]>>pos[i][1];
    }
    cin>>ops;
    for (int i = 0; i < ops; ++i) {
        int n = 0;
        cin>>n;
        int tt = 0, len = 0;
        char oo = ' ';
        cin>>tt>>len;
        cin>>oo;
        mtp[n].push_back(Node(tt,len,oo));
    }

    cin>>que;
    qutime.assign(que, 0);
    for (int i = 0; i < que; ++i) {
        cin>>qutime[i];
    }

    
    if (x - r <= 1 && x + r >= m && y - r <= 1 && y + r >= n) {
        for (int i = 0; i < que; ++i) {
            cout<<pos.size();
            if (i != que - 1) cout<<' ';
        }
        return 0;
    }


    for (auto &x : mtp) {
        sort(x.second.begin(), x.second.end(), cmp);
    }

    vector<int> ans(100000,0);



    for (auto x : mtp) {
        
        int prep = 0, preflg = 0;
        if (isIn(pos[x.first - 1][0],pos[x.first - 1][1])) {
            preflg = 1;
            ans[0]++;
        }
        for (auto c : x.second) {
            preflg = 0;
            if (preflg) {
                for (int i = prep + 1; i < c.t; ++i) {
                    ans[i] ++;
                }
            }
            preflg = 0;
            int ti = pos[x.first - 1][0], tj = pos[x.first - 1][1];
            switch (c.p) {
                case 'A': {
                    ti = (ti - c.l >= 1) ? ti - c.l : 1;
                    break;
                }
                case 'W':{
                    tj = (tj + c.l <= n) ? tj + c.l : n;
                    break;
                }
                case 'S':{
                    tj = (tj - c.l >= 1) ? tj - c.l : 1;
                    break;
                }
                case 'D':{
                    ti = (ti + c.l <= m) ? ti + c.l : m;
                    break;
                }
                default: break;
            }
            pos[x.first - 1][0] = ti;
            pos[x.first - 1][1] = tj;
            if (isIn(ti, tj)) {
                ans[c.t] ++;
                prep = c.t;
                preflg = 1;
            }
        }
    }

    for (int i = 0; i < que; ++i) {
        cout<<ans[qutime[i]];
        if (i != que - 1) cout<<' ';
    }
    return 0;
}