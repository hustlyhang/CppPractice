#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> nums;
vector<int> x{0,0,1,-1},y{1,-1,0,0};
int ans;

int n = 0, m = 0, tt = 0;

void dfs(int i, int j, int k, int t, int a){
    if (i == n - 1 && j == m - 1 && t == tt) {
        if (t%nums[i][j] == 0) a++;
        ans = max(ans, a);
        return;
    }
    if (t > tt || ((tt - t) < (n - i - 1 + m - j - 1))) return;
    for (int l = 0; l < 4; ++l) {
        if (i + x[l] < n && i + x[l] >= 0 && j + y[l] < m && j + y[l] >= 0) {
            if (k == -1) {
                dfs(i + x[l], j + y[l], l, t+1, 0);
            }
            else if (i + x[l] != i - x[k] && j + y[l] != j - y[k]){
                if (t%nums[i][j] == 0){
                    //cout<<"i ="<<i<<"  "<<"j = "<<j<<endl;
                    //cout<<"a ="<<a + 1<<endl;
                    dfs(i + x[l], j + y[l], l, t+1, a + 1);
                }
                else dfs(i + x[l], j + y[l], l, t+1, a);
            }
        }
    }
}

int main(){
    cin>>n>>m>>tt;
    //cout<<tt;
    nums.assign(n,vector<int>(m,0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin>>nums[i][j];
        }
    }

    dfs(0,0,-1,0,0);

    cout<<ans;
    
    return 0;

}