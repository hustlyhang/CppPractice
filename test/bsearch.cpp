#include <iostream>
using namespace std;

int main(){

    // 二分查找，如果找不到的话，那么r会指向第一个小于target的位置，l会指向第一个大于target的位置
    int nums[] = {0,1,2,3,5,5,6,7,8,9};
    int l = 0, r = 9;
    int t = 4;
    while (l <= r) {
        int m = (l + r)>>1;
        if (nums[m] < t) l = m + 1;
        else if (nums[m] > t) r = m - 1;
        else break;
        cout<<"l = " <<l << endl;
        cout<<"r = " <<r << endl;
    }

    return 0;
}