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
private:
    int ans=0;
    void inorder(TreeNode* root, int &i, int k){
        if(root==NULL) return;

        inorder(root->left, i,k);
        i++;
        if(i==k) ans= root->val;
        inorder(root->right,i,k);

    }

public:
    int kthSmallest(TreeNode* root, int k) {
        int i=0;
        inorder(root,i,k);
        return ans;
    }
};