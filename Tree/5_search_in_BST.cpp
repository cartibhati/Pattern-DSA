class Solution {
public:
    TreeNode* ans = NULL;

    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL)
            return NULL;

        if(root->val == val){
            ans = root;
            return ans;
        }

        if(val < root->val)
            return searchBST(root->left, val);
        else
            return searchBST(root->right, val);
    }
};