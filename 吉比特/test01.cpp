#include <iostream>
#include <vector>
using namespace std;



int main(){

    int n;
    cin>>n;
    vector<int> prim{2,3,5,7,11,13,17,19,23,29,31,37,41,43};

    int ret = 0, i = 0;
    while (n % prim[i] != n) {
        while (n % prim[i] == 0) {
            ret++;
            n/=prim[i];
        }
        i++;
    }

    cout<<ret;
    
    return 0;
}