/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // void f(TreeNode* node, vector<int>& ans){
    //     if (node == nullptr) return;
    //     f(node->left, ans);
    //     ans.push_back(node->val);
    //     f(node->right, ans);
    // }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> stk;
        TreeNode* node = root;
        while (true){
            if (node == nullptr){
                if (stk.empty()) break;
                node = stk.top();
                stk.pop();
                ans.push_back(node->val);
                node = node->right;
            }
            else{
                stk.push(node);
                node = node->left;
            }
        }
        return ans;
    }
};