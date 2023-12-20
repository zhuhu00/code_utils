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

// 使用递归的思想进行计算，在判断语句中，只有当left或者right为0时，才会执行后面的1+left+right，所以是左右都加上，而实际执行的时候，只有1+0+0或1+left+0或者1+right+0
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        int left=minDepth(root->left), right = minDepth(root->right);
        return (left&&right) ? 1+min(left, right): 1+left+right;
    }
};