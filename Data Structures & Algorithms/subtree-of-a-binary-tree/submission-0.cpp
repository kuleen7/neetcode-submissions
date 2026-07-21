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
    bool ans=false;
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q ==NULL) return true;
        if(p!=NULL && q==NULL || p==NULL && q!=NULL) return false;

        if(p->val !=q->val) return false;

        bool l = isSameTree(p->left, q->left);
        bool r =isSameTree(p->right, q->right);
        return l&&r;
    }
    
    void check(TreeNode* root, TreeNode* subRoot){
        if(root==NULL) return;
        
        if(isSameTree(root,subRoot)) ans=true;

        check(root->left,subRoot);
        check(root->right,subRoot);
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL) return false;

        if(subRoot==NULL) return true;
        check(root,subRoot);

        return ans;
    }
};