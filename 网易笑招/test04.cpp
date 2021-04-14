
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 该方法接收一个二叉树root和一条输入路径path，返回一个数组，数组包含二叉树中的最优质路径，每个数组元素的值代表二叉树中节点的val
     * @param root TreeNode类 表示一颗二叉树的根节点root，不会为空
     * @param path int整型vector 输入路径path，不会为空
     * @return int整型vector
     */
    vector<TreeNode*> tmp;
    vector<vector<TreeNode*>> p;
    void hs(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr) {
            p.push_back(tmp);
            return;
        }
        if (root->left) {
            tmp.push_back(root->left);
            hs(root->left);
            tmp.pop_back();
        }
        if (root->right) {
            tmp.push_back(root->right);
            hs(root->right);
            tmp.pop_back();
        }
    }
    bool suit(vector<TreeNode*>& tmp, vector<int> &path) {
        int i = 0, j = 0;
        while (i < tmp.size() && j < path.size()) {
            while (path[j] != tmp[i]->val) i++;
            int tmpi = i;
            while (i < tmp.size() && j < path.size() && path[j] == tmp[i]->val) {
                i++;
                j++;
            }
            if (j == path.size()) return true;
            else {
                i = tmpi + 1;
                j = 0;
            }
        }
        return false;
    }
    vector<int> solution(TreeNode *root, vector<int> &path) {
        // write code here
        hs(root);

        vector<int> ret;
        int l  = 0;
        for (auto x : p) {
            if (suit(x, path) && x.size() > l) {
                l = x.size();
                ret.clear();
                for (auto s : x) {
                    ret.push_back(s->val);
                }
            }
        }
        return ret;
    }
};