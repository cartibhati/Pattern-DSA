# Symmetric Tree

![Easy](https://img.shields.io/badge/Difficulty-Easy-green)
🔗 **[Problem Link](https://leetcode.com/problems/symmetric-tree/)**

---

## 📝 Problem Description

Given the `root` of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

---

## 💡 Intuition & Core Logic

A binary tree is symmetric if its left subtree is a mirror reflection of its right subtree.

### Recursive Mirror Approach
We can write a helper function `isMirror(a, b)` that checks whether two trees `a` and `b` are mirror images of each other:

1. **Base Cases**:
   - If both `a` and `b` are `nullptr`, both branches ended simultaneously $\rightarrow$ return `true`.
   - If only one of `a` or `b` is `nullptr`, the tree structures are asymmetrical $\rightarrow$ return `false`.
   - If `a->val != b->val`, values at corresponding mirror positions differ $\rightarrow$ return `false`.

2. **Recursive Traversal**:
   - Left child of `a` must mirror Right child of `b`: `isMirror(a->left, b->right)`.
   - Right child of `a` must mirror Left child of `b`: `isMirror(a->right, b->left)`.
   - Both mirror conditions must hold true $\rightarrow$ return `r1 && r2`.

For the root of the tree, we simply call `isMirror(root->left, root->right)`.

---

## 🔄 Step-by-Step Dry Run

Consider the following symmetric Binary Tree:

```text
        1
       / \
      2   2
     / \ / \
    3  4 4  3
```

1. **Root Call**:
   - `isSymmetric(root)` calls `isMirror(left node 2, right node 2)`.

2. **At Mirror Pair (`a = 2 (left)`, `b = 2 (right)`)**:
   - Both non-null, values equal (`2 == 2`).
   - Compute `r1 = isMirror(a->left (3), b->right (3))`:
     - Both non-null, values equal (`3 == 3`).
     - Recurse children (all `nullptr`) $\rightarrow$ returns `true`.
   - Compute `r2 = isMirror(a->right (4), b->left (4))`:
     - Both non-null, values equal (`4 == 4`).
     - Recurse children (all `nullptr`) $\rightarrow$ returns `true`.
   - Returns `r1 && r2 = true && true = true`.

3. **Final Result**:
   - Returns `true`. The tree is symmetric!

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
    bool isMirror(TreeNode* a, TreeNode* b){
        if(a==NULL && b==NULL)
        return true;
        if(a==NULL || b==NULL)
        return false;
        if(a->val != b->val)
        return false;
        bool r1=isMirror(a->left,b->right);
        bool r2=isMirror(a->right,b->left);
        return r1 && r2;
    }
    bool isSymmetric(TreeNode* root) {
        return isMirror(root->left,root->right);
    }
};
```

---

## 📊 Complexity Analysis

- **Time Complexity**: $\mathcal{O}(N)$ — Where $N$ is the total number of nodes in the binary tree. We visit each node at most once.
- **Space Complexity**: $\mathcal{O}(H)$ — Call stack depth where $H$ is the height of the tree ($\mathcal{O}(N)$ in the worst case for a skewed tree, $\mathcal{O}(\log N)$ for a balanced tree).
