#include <iostream>
#include <vector>
#include <time.h>
using namespace std;


// 注意这儿孩子节点是×2加一
void adjust(vector<int>& nums, int p, int len){
    int j = p * 2 + 1;
    while (j < len) {
        if (j + 1 < len && nums[j] < nums[j + 1]) j++;
        if (nums[p] < nums[j]) {
            swap(nums[p], nums[j]);
            p = j;
            j = j * 2 + 1;
        }
        else break;
    }
    return;
}

void HeadSort(vector<int>& nums) {
    int len = nums.size();
    for (int i = len / 2 - 1; i >= 0; --i) {
        adjust(nums, i, len);
    }
    for (int i = len - 1; i > 0; --i) {
        swap(nums[i], nums[0]);
        adjust(nums, 0, i);
    }
}

void QuickSort(vector<int>& nums, int l, int r){
    if (l >= r) return;
    srand((unsigned)time(NULL));
    int tl = l, tr = r;
    int t = rand() % (r - l + 1);
    swap(nums[l], nums[t + l]);
    int tmp = nums[l];
    while (tl < tr) {
        while (tl < tr && nums[tr] > tmp) tr--;
        nums[tl] = nums[tr];
        while (tl < tr && nums[tl] <= tmp) tl++;
        nums[tr] = nums[tl];
    }
    nums[tl] = tmp;
    QuickSort(nums, l, tl - 1);
    QuickSort(nums, tl + 1, r);
}


int main(){
    int n = 0;
    cin>>n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; ++i) cin>>nums[i];
    // HeadSort(nums);
    QuickSort(nums, 0, n - 1);
    for (auto x : nums) cout<<x<<',';
    cout<<endl;

    return 0;
}