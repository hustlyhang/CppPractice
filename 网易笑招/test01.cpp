
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
  public:
    int maxMoney(TreeNode *root) {
        // write code here
        int ret = 0 ;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *tmp = q.front();
            q.pop();
            if (tmp->left != nullptr && tmp->right != nullptr &&
                tmp->left->left == nullptr && tmp->left->right == nullptr &&
                tmp->right->left == nullptr && tmp->right->right == nullptr) {
                ret += 5;
            } else if (tmp->left != nullptr && tmp->left->left == nullptr &&
                       tmp->left->right == nullptr && tmp->right == nullptr) {
                ret += 2;
            } else if (tmp->right != nullptr && tmp->right->left == nullptr &&
                       tmp->right->right == nullptr && tmp->left == nullptr) {
                ret += 2;
            }
            if (tmp->left) q.push(tmp->left);
            if (tmp->right) q.push(tmp->right);
        }

        return ret;
    }
};