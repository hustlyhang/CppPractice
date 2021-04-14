#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int ret = 0;

int dd(vector<int>& nums, int start) {
    //? 三个数字不满足情况时会有三种情况
    /*
        * 一、1,2差距过大
        * 二、2，3 差距过大
        
    */
   int a = start, b= start + 1, c = start + 2;
   int len = nums.size();

   //? 当前三个数全部满足
   if (a < len && b < len && c < len && nums[a] <= nums[b] && nums[b] <= nums[c] && nums[b] - nums[a] <= 10 && nums[c] - nums[b] <= 10) {
       return 3;
   }

   //? 前两个数不满足
   if (a < len && b < len && nums[b] - nums[a] > 10 && nums[b] - nums[a] <= 20) {
       //? 需要添加一个数
       ret++;
       return 2;
   }
    //? 前两个数不满足
   if (a < len && b < len && nums[b] - nums[a] > 20) {
       //? 需要添加两个数
       ret+=2;
       return 1;
   }
   //? 前两个数满足
   if (a < len && b < len  && nums[b] - nums[a] <= 10) {
       //? 需要添加一个数
       ret+=1;
       return 2;
   }
   //? 只剩最后一个数字
   if (a == len - 1) {
       ret+=2;
       return 1;
   }
   return 0;
}

int main() {

    int n = 0;
    cin>>n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; ++i) {
        cin>> nums[i];
    }

    sort(nums.begin(), nums.end());

    int k = 0;
    while (k < n) {
        //cout<<"k="<<k<<endl;
        k+=dd(nums, k);
    }
    
    cout<< ret;


    return 0;
}