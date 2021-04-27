#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int r, c, obs, seltobs;
vector<vector<char>> ch;
vector<int> obsnum;
vector<int> flg;
vector<vector<int>> sch;
vector<int> tmp;
int ans = -1;
int b, e;

vector<int> x{0,0,-1,1}, y{1,-1,0,0};

int bfs() {
    flg.assign(r*c,1);
    int ps = 0;
    queue<int> q;
    q.push(b);
    flg[b] = 0;
    int cur = 1, next = 0;
    bool f = false;
    while (!q.empty()) {

        for (int i = 0; i < cur; ++i) {
            int tm = q.front();
            q.pop();
            if (ch[tm/c][tm%c] == 'T') {
                f = true;
                break;
            }
            for (int k = 0; k < 4; ++k) {
                int tmpi = tm/c + x[k], tmpj = tm%c + y[k];
                if (tmpi >= 0 && tmpi < r && tmpj >= 0 && tmpj < c && flg[tmpi*c + tmpj] && ch[tmpi][tmpj] != '#') {
                    q.push(tmpi*c+tmpj);
                    flg[tmpi*c + tmpj] = 0;
                    next++;
                }
            }
        }
        cur = next;
        next = 0;
        ps++;
    }
    return f ? ps : -1;
}


void dealch(vector<int>& sh) {
    for (int i = 0; i < sh.size(); ++i) {
        ch[sh[i]/c][sh[i]%c] = '#';
    }
    // for (int i = 0; i < r; ++i) {
    //     for (int j = 0; j < c; ++j) {
    //         cout<<ch[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }
}
void dfs(int start) {
    if (tmp.size() == seltobs) {
        sch.push_back(tmp);
        return;
    }
    if (start >= obsnum.size()) return;
    for (int i = start; i < obsnum.size(); ++i) {
        tmp.push_back(obsnum[i]);
        dfs(i + 1);
        tmp.pop_back();
    }
}
int main() {
    cin>>r>>c>>obs>>seltobs;
    flg.assign(r*c,1);
    ch.assign(r, vector<char>(c));
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin>>ch[i][j];
            if (ch[i][j] == '?') {
                obsnum.push_back(i*c+j);
            }
            if (ch[i][j] == 'S') b = i*c +j;
            if (ch[i][j] == 'T') e = i*c +j;
        }
    }
    // 生成方案
    dfs(0);
    if (bfs() == -1) {
        cout<<-1;
        return 0;
    }
    auto tmpch = ch;
    for (int i = 0; i < sch.size(); ++i) {
        ch = tmpch;
        dealch(sch[i]);
        bool isconti = true;
        for (int k = 0; k < 4; ++k) {
            int tmpi = e/c + x[k], tmpj = e%c + y[k];
            if (tmpi >= 0 && tmpi < r && tmpj >= 0 && tmpj < c) {
                if (ch[tmpi][tmpj] == '#') continue;
                else {
                    isconti = false;
                    break;
                }
            }
        }
        if (isconti) continue;
        isconti = true;
        for (int k = 0; k < 4; ++k) {
            int tmpi = b/c + x[k], tmpj = b%c + y[k];
            if (tmpi >= 0 && tmpi < r && tmpj >= 0 && tmpj < c) {
                if (ch[tmpi][tmpj] == '#') continue;
                else {
                    isconti = false;
                    break;
                }
            }
        }
        if (isconti) continue;
        isconti = true;
        for (int i = b/c; i < e/c; ++i) {
            for (int j = 0; j < c; ++j) {
                if (ch[i][j] == '#') continue;
                else {
                    isconti = false;
                    break;
                }
            }
            if (isconti) break;
        }
        if (isconti) continue;
        
        int ret = bfs();
        ans = max(ans, ret);
    }
    cout<<ans;
    return 0;

}