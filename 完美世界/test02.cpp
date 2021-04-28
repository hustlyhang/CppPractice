#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main(){
    int num = 0;
    vector<int> nums;
    while (cin>>num) {
        nums.push_back(num);
    }
    int sum = 0;
    for (auto x : nums) {
        sum^=x;
    }

    cout<<sum;





    return 0;
}