#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,m,t;
vector<vector<int>> nums;
vector<vector<int>> op;
struct Node{
    int row, num;
    Node(int _r, int _n):row(_r),num(_n){};
};
static bool cmpl(Node& a, Node& b){
    if (a.num == b.num) return a.row < b.row;
    else return a.num < b.num; 
}
static bool cmpb(Node& a, Node& b){
    if (a.num == b.num) return a.row < b.row;
    else return a.num > b.num; 
}

void deal(int p) {
    int bi = op[p][0] - 1, ei = op[p][1] -1 , bj = op[p][2] - 1, ej = op[p][3] - 1, s = op[p][4] - 1;
    int flg = op[p][5];
    if (bi == ei) return;
    vector<Node> n;
    for (int i = bi; i <= ei; ++i) {
        n.push_back(Node(i, nums[i][s]));
    }
    if (flg == 1) sort(n.begin(), n.end(), cmpb);
    if (flg == 0) sort(n.begin(), n.end(), cmpl);

    vector<vector<int>> tm(ei - bi + 1, vector<int>(ej - bj + 1));
    int indexi = 0, indexj = 0;
    for (auto x : n) {
        indexj = 0;
        for (int j = bj; j <= ej; ++j) {
            tm[indexi][indexj] = nums[x.row][j];
            indexj++;
        }
        indexi++;
    }

    indexj = 0;
    indexi = 0;
    for (int i = bi; i <= ei; ++i) {
        indexj = 0;
        for (int j = bj; j <= ej; ++j) {
            nums[i][j] = tm[indexi][indexj];
            indexj++;
        }
        indexi++;
    }
}

int main(){
    cin>>n>>m>>t;
    nums.assign(n, vector<int>(m, 0));
    op.assign(t,vector<int>(6));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin>>nums[i][j];
        }
    }
    if (n == 1) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout<<nums[i][j];
                if (j != m - 1) cout<<' ';
            }
            if (i != n - 1) cout<<endl;
        }
        return 0;
    }
    for (int i = 0; i < t; ++i) {
        for (int j = 0; j < 6; ++j) {
            cin>>op[i][j];
        } 
    }
    for (int i = 0; i < t; ++i) {
        //cout<<"deal"<<endl;
        deal(i);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout<<nums[i][j];
            if (j != m - 1) cout<<' ';
        }
        if (i != n - 1) cout<<endl;
    }

    return 0;
}