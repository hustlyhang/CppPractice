#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int _val):val(_val), next(nullptr){};
    ListNode(int _val, ListNode* _next):val(_val), next(_next){};
};
void deal1(){
    vector<int> nums;
    int num = 0;
    while (cin>>num) {
        nums.push_back(num);
    }
    int pos = nums[nums.size() - 1];
    nums.pop_back();
    nums.erase(nums.begin() + nums.size() - pos);
    for (auto x : nums) {
        cout<<x<<' ';
    }
}
int main(){
    ListNode* Head = new ListNode(0);
    ListNode* cur = Head;
    int num = 0, len = 0;
    while (cin>>num) {
        ListNode* tmp = new ListNode(num);
        cur->next = tmp;
        cur = tmp;
        len++;
    }
    int pos = cur->val;
    cur = Head;
    for (int i = 0; i < len - pos; ++i) {
        cur = cur->next;
    }
    cur->next = cur->next->next;
    cur = Head;
    while (cur->next->next) {
        cur = cur->next;
    }
    cur->next = nullptr;
    cur = Head;
    while (cur) {
        cout<<cur->val<<' ';
        cur = cur->next;
    }

    return 0;
}