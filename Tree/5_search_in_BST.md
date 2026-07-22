# Search in a Binary Search Tree

![Easy](https://img.shields.io/badge/Difficulty-Easy-green)
🔗 **[Problem Link](https://leetcode.com/problems/search-in-a-binary-search-tree/)**

---

## 📝 Problem Description

You are given the root of a binary search tree (BST) and an integer `val`.

Find the node in the BST that the node's value equals `val` and return the subtree rooted with that node. If such a node does not exist, return `null`.

---

## 💡 Intuition & Core Logic

A Binary Search Tree (BST) has a key property: for any given node, all values in its left subtree are less than the node's value, and all values in its right subtree are greater than the node's value. 

We can leverage this property to search for `val` in $\mathcal{O}(H)$ time instead of scanning the entire tree:

### Recursive Approach
1. **Base Cases**:
   - If the current node `root` is `nullptr`, the value does not exist in the BST $\rightarrow$ return `nullptr`.
   - If `root->val == val`, we have found the target node $\rightarrow$ return `root`.

2. **Search Direction**:
   - If `val < root->val`, the target value must lie in the left subtree if it exists $\rightarrow$ recursively search the left child: `searchBST(root->left, val)`.
   - If `val > root->val`, the target value must lie in the right subtree if it exists $\rightarrow$ recursively search the right child: `searchBST(root->right, val)`.

---

## 🔄 Step-by-Step Dry Run

Consider the following BST:

```text
        4
       / \
      2   7
     / \
    1   3
```

We want to search for **`val = 2`**.

1. **Start at Root Node `4`**:
   - `root != nullptr` and `root->val != 2` (`4 != 2`).
   - Since `2 < 4`, recurse left: `searchBST(root->left, 2)` (which calls node `2`).

2. **At Node `2`**:
   - `root != nullptr`.
   - `root->val == 2` (`2 == 2`).
   - Store node `2` in `ans` and return `ans`.

**Final Result**: The function returns the subtree rooted at `2`:
```text
      2
     / \
    1   3
```

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
```

---

## 📊 Complexity Analysis

- **Time Complexity**: $\mathcal{O}(H)$ — Where $H$ is the height of the BST. In the worst case (skewed tree), we might traverse $N$ nodes $\rightarrow \mathcal{O}(N)$. In a balanced BST, the height is $\mathcal{O}(\log N)$, making the search very efficient.
- **Space Complexity**: $\mathcal{O}(H)$ — Representing the recursion call stack depth. Similar to time complexity, this is $\mathcal{O}(\log N)$ for a balanced tree and $\mathcal{O}(N)$ for a skewed tree.
