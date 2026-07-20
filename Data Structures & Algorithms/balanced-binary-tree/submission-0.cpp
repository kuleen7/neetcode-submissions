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
    bool check= true;

    int height(TreeNode* root){
        if(root==NULL) return 0;

        int l= height(root->left);
        int r= height(root->right);
        int ans = l-r;
        int h= 1+max(l,r);
        if(ans < -1 || ans > 1) check = false;
        return h;
    }

    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        int h= height(root);
        return check;
    }
};