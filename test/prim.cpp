#include <iostream>
#include <vector>
using namespace std;
int nums[400000000];
typedef long long ll;
int prim(int n) {
    int ans = 0;
    for (int i = 2; i <= n; ++i) {
        if (nums[i] > 0) {
            ans++;
            for (int j = i; j <= n; j = j + i) {
                nums[j] = -1;
            }
        }
    }
    return ans;
}

int main(){
    int n = 0;
    cin >> n;
    for (int i = 0; i <= n; ++i){
        nums[i] = i;
    }
    int p = prim(n);
    // for (auto x : p) {
    //     cout<<x<<' ';
    // }
    cout<<p;
    return 0;
}