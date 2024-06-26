/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* f(TreeNode* node, TreeNode* p, TreeNode* q){
        if (node == nullptr || node == p || node == q) return node;
        TreeNode* l = f(node->left, p, q);
        TreeNode* r = f(node->right, p, q);
        if (l && r) return node;
        if (l) return l;
        return r;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return f(root, p, q);
    }
};