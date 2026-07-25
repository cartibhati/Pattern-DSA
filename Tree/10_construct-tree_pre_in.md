# Construct Binary Tree from Preorder and Inorder Traversal

![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow)
🔗 **[Problem Link](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)**

---

## 📝 Problem Description

Given two integer arrays `preorder` and `inorder` where `preorder` is the preorder traversal of a binary tree and `inorder` is the inorder traversal of the same tree, construct and return the binary tree.

---

## 💡 Intuition & Core Logic

1. **Preorder Traversal**: Follows the **Root $\rightarrow$ Left $\rightarrow$ Right** order. Thus, the first element of `preorder` is always the root of the tree.
2. **Inorder Traversal**: Follows the **Left $\rightarrow$ Root $\rightarrow$ Right** order. Once we find the root value in the `inorder` array, we can determine:
   - Elements to the left of the root index belong to the **left subtree**.
   - Elements to the right of the root index belong to the **right subtree**.
3. **Optimizing Root Lookup**: Instead of searching for the root index in the `inorder` array linearly, we can use an `unordered_map` to map each value to its index in `inorder` in $\mathcal{O}(1)$ time.
4. **Recursion**:
   - Construct the node with the value at the current index of `preorder` (`preorder[idx]`).
   - Increment `idx`.
   - Find the root's index (`id`) in `inorder`.
   - Recurse for the left subtree using the range `[low, id - 1]`.
   - Recurse for the right subtree using the range `[id + 1, high]`.

---

## 🔄 Step-by-Step Dry Run

### Input
- `preorder = [3, 9, 20, 15, 7]`
- `inorder = [9, 3, 15, 20, 7]`

### Map Initialization (Inorder Index Map)
- `in = {9: 0, 3: 1, 15: 2, 20: 3, 7: 4}`
- `idx = 0` (tracks position in `preorder`)

### Recursive Tree Construction
1. **Call `fun(preorder, 0, 4)`**:
   - Current root value = `preorder[0] = 3`. Increment `idx` to `1`.
   - Root index in `inorder` is `id = 1`.
   - Create `node(3)`.
   - Build left subtree: Call `fun(preorder, 0, 0)`.
   - Build right subtree: Call `fun(preorder, 2, 4)`.

2. **Left Subtree `fun(preorder, 0, 0)`**:
   - Current root value = `preorder[1] = 9`. Increment `idx` to `2`.
   - Root index in `inorder` is `id = 0`.
   - Create `node(9)`.
   - Left subtree of `9`: Call `fun(preorder, 0, -1)` $\rightarrow$ Returns `nullptr` (since `low > high`).
   - Right subtree of `9`: Call `fun(preorder, 1, 0)` $\rightarrow$ Returns `nullptr` (since `low > high`).
   - Return `node(9)` to `node(3)->left`.

3. **Right Subtree `fun(preorder, 2, 4)`**:
   - Current root value = `preorder[2] = 20`. Increment `idx` to `3`.
   - Root index in `inorder` is `id = 3`.
   - Create `node(20)`.
   - Build left subtree: Call `fun(preorder, 2, 2)`.
   - Build right subtree: Call `fun(preorder, 4, 4)`.

4. **Subtree `fun(preorder, 2, 2)`**:
   - Current root value = `preorder[3] = 15`. Increment `idx` to `4`.
   - Root index in `inorder` is `id = 2`.
   - Create `node(15)`.
   - Left subtree of `15`: Call `fun(preorder, 2, 1)` $\rightarrow$ Returns `nullptr`.
   - Right subtree of `15`: Call `fun(preorder, 3, 2)` $\rightarrow$ Returns `nullptr`.
   - Return `node(15)` to `node(20)->left`.

5. **Subtree `fun(preorder, 4, 4)`**:
   - Current root value = `preorder[4] = 7`. Increment `idx` to `5`.
   - Root index in `inorder` is `id = 4`.
   - Create `node(7)`.
   - Left subtree of `7`: Call `fun(preorder, 4, 3)` $\rightarrow$ Returns `nullptr`.
   - Right subtree of `7`: Call `fun(preorder, 5, 4)` $\rightarrow$ Returns `nullptr`.
   - Return `node(7)` to `node(20)->right`.

6. **Return `node(20)` to `node(3)->right`**.
7. **Return `node(3)` as the root of the constructed tree**.

---

## 💻 C++ Working Code

```cpp
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
    int idx=0;
    unordered_map<int,int>in;
    TreeNode* fun(vector<int>& preorder, int low, int high) {
        if(low > high)
            return NULL;

        TreeNode* node = new TreeNode(preorder[idx]);
        idx++;

        int id = in[node->val];

        node->left = fun(preorder, low, id - 1);
        node->right = fun(preorder, id + 1, high);

        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++){
            in[inorder[i]]=i;
        }
        return fun(preorder,0,inorder.size()-1);
    }
};
```

---

## 📊 Complexity Analysis

- **Time Complexity**: $\mathcal{O}(N)$ — Where $N$ is the number of nodes in the binary tree. We construct each node exactly once and look up the inorder indices in $\mathcal{O}(1)$ time using the hash map.
- **Space Complexity**: $\mathcal{O}(N)$ — Where $N$ is the number of nodes. We store the elements and indices of `inorder` in an `unordered_map` of size $N$, and the recursion stack can go up to $\mathcal{O}(N)$ in the worst case (skewed tree) or $\mathcal{O}(\log N)$ in the best case (balanced tree).
