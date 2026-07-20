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
    int maxd=0;

    int height(TreeNode* root){
        if(root==NULL) return 0;
        int l = height(root->left);
        int r = height(root->right);
        int ans = 1+max(l,r);
        maxd= max(maxd,l+r);
        return ans;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int h = height(root);
        return maxd;
        
    }
};