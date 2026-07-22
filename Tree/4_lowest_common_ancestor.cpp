class Solution {
public:
    TreeNode* ans = NULL;

    int fun(TreeNode* node, TreeNode* p, TreeNode* q){
        if(node == NULL) return 0;

        int left = fun(node->left, p, q);
        int right = fun(node->right, p, q);

        int self = (node == p || node == q) ? 1 : 0;

        if(left + right + self >= 2 && ans == NULL){
            ans = node;
        }

        return left + right + self;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        fun(root, p, q);
        return ans;
    }
};