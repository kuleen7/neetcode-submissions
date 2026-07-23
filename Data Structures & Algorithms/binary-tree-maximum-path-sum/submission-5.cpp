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
    int maxsum=INT_MIN;

    int maxpath(TreeNode* root){
        if(root==NULL) return 0;

        int l=maxpath(root->left);
        int r=maxpath(root->right);
        if(l<0) l=0;
        if(r<0) r=0;
        int nodeSum = l+r+root->val;
        maxsum= max(maxsum,nodeSum);
        return root->val+max(l,r);
    }

    int maxPathSum(TreeNode* root) {
        if(root==NULL) return 0;
        int ans=maxpath(root);
        return maxsum;
    }
};