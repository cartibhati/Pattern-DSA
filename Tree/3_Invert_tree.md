# Invert Binary Tree

![Easy](https://img.shields.io/badge/Difficulty-Easy-green)
🔗 **[Problem Link](https://leetcode.com/problems/invert-binary-tree/)**

---

## 📝 Problem Description

Given the `root` of a binary tree, invert the tree, and return its root.

---

## 💡 Intuition & Core Logic

Inverting a binary tree involves swapping the left and right pointers of every node in the tree, effectively creating its mirror image.

### Recursive Approach
1. **Base Case**: If `root == nullptr`, return immediately.
2. **Swap Children**: Swap the pointers `root->left` and `root->right` using `std::swap`.
3. **Recursive Traversal**:
   - Recursively invert the new left subtree: `fun(root->left)`.
   - Recursively invert the new right subtree: `fun(root->right)`.

---

## 🔄 Step-by-Step Dry Run

Consider the following Binary Tree:

```text
       4
     /   \
    2     7
   / \   / \
  1   3 6   9
```

1. **At Root Node (`4`)**:
   - `swap(root->left, root->right)` $\rightarrow$ Node `4`'s left child becomes `7`, right child becomes `2`.
   - Tree after root swap:
     ```text
          4
        /   \
       7     2
      / \   / \
     6   9 1   3
     ```
   - Call `fun(7)` and `fun(2)`.

2. **At Node `7`**:
   - `swap(node 7->left, node 7->right)` $\rightarrow$ Left child becomes `9`, right child becomes `6`.
   - Recurse on children `9` and `6` (leaf nodes: swap `nullptr`, base cases return).

3. **At Node `2`**:
   - `swap(node 2->left, node 2->right)` $\rightarrow$ Left child becomes `3`, right child becomes `1`.
   - Recurse on children `3` and `1` (leaf nodes: swap `nullptr`, base cases return).

4. **Final Inverted Tree**:
   ```text
        4
      /   \
     7     2
    / \   / \
   9   6 3   1
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
    void fun(TreeNode* root) {
        if (root == NULL)
            return;

        swap(root->left, root->right);

        fun(root->left);
        fun(root->right);
    }

    TreeNode* invertTree(TreeNode* root) {
        fun(root);
        return root;
    }
};
```

---

## 📊 Complexity Analysis

- **Time Complexity**: $\mathcal{O}(N)$ — Where $N$ is the number of nodes in the binary tree. We visit and swap children for each node once.
- **Space Complexity**: $\mathcal{O}(H)$ — Where $H$ is the height of the tree, representing the recursion call stack depth ($\mathcal{O}(N)$ for skewed tree, $\mathcal{O}(\log N)$ for balanced tree).
