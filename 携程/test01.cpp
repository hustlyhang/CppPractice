#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include <string>
#include <queue>
#include <math.h>
using namespace std;


/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^ 
******************************开始写代码******************************/
struct TreeNode{
    char c;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char t):c(t),left(nullptr),right(nullptr){};
};
string ret;
TreeNode* build(int n) {
    TreeNode* root = new TreeNode('R');
    queue<TreeNode*> q;
    if (n == 1) return root;
    q.push(root);
    int k = 1, tmp = 0;
    int l = 1;
    while (l < n) {

        for (int j = 0; j < k; ++j) {
            TreeNode* t = q.front();
            q.pop();
            t->left = new TreeNode('G');
            t->right = new TreeNode('R');
            q.push(t->left);
            q.push(t->right);
            tmp+=2;
        }
        l++;
        k = tmp;
        tmp = 0;
    }
    return root;
}
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    ret+=root->c;
    inorder(root->right);

}
string buildingHouse(string s) {
    int len = s.size();
    if (len == 0) return "N";
    for (auto c : s) {
        if (c >'9' || c < '0') return "N";
    }

    if (s[0] == '0') return "N";
    int n = 0;
    len--;
    for (auto c : s) {
        n += (c - '0') * pow(10, len--);
    }
    if (n > 12 || n<= 0 ) return "O";
    TreeNode* root = build(n);
    inorder(root);
    return ret;

    //  GRR

}
/******************************结束写代码******************************/


int main() {
    string res;

    string _n;
    getline(cin, _n);
    
    res = buildingHouse(_n);
    cout << res << endl;
    
    return 0;

}