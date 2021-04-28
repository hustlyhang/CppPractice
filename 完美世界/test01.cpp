#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;



int main(){
    vector<int> nums;
    int num = 0;
    while (cin>>num) nums.push_back(num);
    int pos = nums[0];
    int times = 0;
    int ans = -1;
    for (int i = 0; i < nums.size(); ++i) {
        while (i < nums.size() && nums[i] == pos) {
            i++;
            times++;
            if (times > nums.size() / 4) {
                ans = nums[i];
                break;
            }
        }
        pos = nums[i];
        i--;
        
        times = 0;
    }

    cout<<ans;





    return 0;
}