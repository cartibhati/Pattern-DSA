# Diameter of Binary Tree

![Easy](https://img.shields.io/badge/Difficulty-Easy-green)
🔗 **[Problem Link](https://leetcode.com/problems/diameter-of-binary-tree/)**

---

## 📝 Problem Description

Given the `root` of a binary tree, return the length of the **diameter** of the tree.

The **diameter** of a binary tree is the **length of the longest path** between any two nodes in a tree. This path may or may not pass through the `root`.

The length of a path between two nodes is represented by the number of edges between them.

---

## 💡 Intuition & Core Logic

The diameter of a binary tree is the maximum distance between any two nodes. For any given node in the tree, the longest path that passes through it as the highest point (curving node) will have a length of:
$$\text{Diameter at Node} = \text{height of left subtree} + \text{height of right subtree}$$

We can traverse the tree using Depth-First Search (DFS) to calculate the height of each node, and simultaneously update our maximum diameter encountered so far.

### Recursive Approach
1. **Define a Global/Member Variable**: `res = 0` to store the maximum diameter found.
2. **Post-order Traversal (`height` function)**:
   - **Base Case**: If root is `nullptr`, height is `0`.
   - **Recurse Left & Right**: Calculate the height of the left subtree (`left`) and right subtree (`right`).
   - **Update Diameter**: The path passing through the current node has length `left + right`. Update `res` with the maximum of `res` and `left + right`.
   - **Return Height**: Return the height of the current node to its parent, which is `1 + max(left, right)`.
3. **Execution**: Call `height(root)` and return `res`.

---

## 🔄 Step-by-Step Dry Run

Consider the following binary tree:

```text
        1
       / \
      2   3
     / \
    4   5
```

Let's track the `height` calls and `res` updates:

1. **Leaf Node `4`**:
   - `height(nullptr)` for left and right children returns `0`.
   - `res = max(0, 0 + 0) = 0`.
   - Returns `1 + max(0, 0) = 1` to parent `2`.

2. **Leaf Node `5`**:
   - `height(nullptr)` for left and right children returns `0`.
   - `res = max(0, 0 + 0) = 0`.
   - Returns `1 + max(0, 0) = 1` to parent `2`.

3. **Node `2`**:
   - `left = height(4) = 1`, `right = height(5) = 1`.
   - `res = max(0, 1 + 1) = 2` (Path: `4 -> 2 -> 5`).
   - Returns `1 + max(1, 1) = 2` to parent `1`.

4. **Leaf Node `3`**:
   - `height(nullptr)` for left and right children returns `0`.
   - `res = max(2, 0 + 0) = 2`.
   - Returns `1 + max(0, 0) = 1` to parent `1`.

5. **Root Node `1`**:
   - `left = height(2) = 2`, `right = height(3) = 1`.
   - `res = max(2, 2 + 1) = 3` (Path: `4 -> 2 -> 1 -> 3` or `5 -> 2 -> 1 -> 3`).
   - Returns `1 + max(2, 1) = 3`.

**Final Output (`res`)**: `3`

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
    int res=0;

    int height(TreeNode* root) {
        if (root == NULL)
            return 0;

        int left = height(root->left);
        int right = height(root->right);

        res = max(res, left + right);

        return 1 + max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return res;
    }
};
```

---

## 📊 Complexity Analysis

- **Time Complexity**: $\mathcal{O}(N)$ — Where $N$ is the number of nodes in the binary tree. We visit each node exactly once.
- **Space Complexity**: $\mathcal{O}(H)$ — Where $H$ is the height of the tree, representing the call stack depth. In the worst case of a skewed tree, $H = \mathcal{O}(N)$; in a balanced tree, $H = \mathcal{O}(\log N)$.
