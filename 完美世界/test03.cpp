#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int deal(int n, int k, int flg) {
    if (n > 1) {
        if (k <= pow(2, n - 2)) {
            if (flg == 1)
                return deal(n - 1, k, 1);
            else return deal(n - 1, k, 0);
        }
        else {
            if (flg == 1)
                return deal(n - 1, k - pow(2, n - 2), 0);
            else return deal(n - 1, k - pow(2, n - 2), 1);
        }
    }
    else {
        if (flg == 0) return 0;
        else return 1;
    }
}

int main(){
    int n = 0, k = 0;
    cin>>n>>k;

    cout<<deal(n, k, 0);
    return 0;
}