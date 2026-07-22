# Lowest Common Ancestor of a Binary Tree

![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow)
🔗 **[Problem Link](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/)**

---

## 📝 Problem Description

Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes `p` and `q` as the lowest node in `T` that has both `p` and `q` as descendants (where we allow a node to be a descendant of itself).”

---

## 💡 Intuition & Core Logic

We can find the Lowest Common Ancestor (LCA) using a post-order Depth-First Search (DFS) traversal. The main idea is to count how many of the target nodes (`p` and `q`) reside in the subtree of the current node (including the current node itself).

### Recursive Approach
1. **Helper Function (`fun`)**:
   - We define a recursive function `fun(TreeNode* node, TreeNode* p, TreeNode* q)` that returns `1` if either `p` or `q` is found in the subtree (or is the current node), and `2` if both are found.
   
2. **Base Cases**:
   - If the current node is `nullptr`, return `0`.

3. **Subtree Check**:
   - Recurse on the left child: `int left = fun(node->left, p, q)`.
   - Recurse on the right child: `int right = fun(node->right, p, q)`.
   - Check if the current node itself is one of the target nodes: `int self = (node == p || node == q) ? 1 : 0`.

4. **LCA Identification**:
   - If the sum of matching nodes from the left subtree, right subtree, and current node is at least `2` (`left + right + self >= 2`), and we haven't already set the answer (`ans == nullptr`), then the current node is the LCA.
   - Since we are traversing bottom-up (post-order), the first node to satisfy this condition will naturally be the lowest one.

5. **Return Value**:
   - Return `left + right + self` to inform parent calls about the number of target nodes found.

---

## 🔄 Step-by-Step Dry Run

Consider the following binary tree:

```text
        3
       / \
      5   1
     / \ / \
    6  2 0  8
      / \
     7   4
```

We want to find the LCA of **`p = 5`** and **`q = 4`**.

1. **Start DFS at Root Node `3`**:
   - Recurse left: `fun(5, p, q)`.

2. **At Node `5`**:
   - Recurse left: `fun(6, p, q)`.
     - At Node `6`: both children are null (returns `0`), `self = 0` (6 is neither 5 nor 4). Returns `0`.
   - Recurse right: `fun(2, p, q)`.
     - At Node `2`:
       - Recurse left: `fun(7, p, q)` $\rightarrow$ returns `0`.
       - Recurse right: `fun(4, p, q)`.
         - At Node `4`: both children null, `self = 1` (since 4 is `q`). Returns `1`.
       - At Node `2`: `left = 0`, `right = 1`, `self = 0`. Sum = `1`. Returns `1` to Node `5`.
   - At Node `5`: `left = 0` (from node 6), `right = 1` (from node 2), `self = 1` (since 5 is `p`).
     - Sum = `left + right + self = 0 + 1 + 1 = 2`.
     - Since Sum $\ge 2$ and `ans` is currently `nullptr`, we update `ans = 5`.
     - Returns `2` to Node `3`.

3. **Back to Node `3`**:
   - `left` subtree returns `2`.
   - `right` subtree recursion `fun(1, p, q)` runs, but does not find any matching nodes (returns `0`).
   - `ans` remains `5`.

**Final Result**: LCA is Node `5`.

---

## 💻 C++ Working Code

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
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
```

---

## 📊 Complexity Analysis

- **Time Complexity**: $\mathcal{O}(N)$ — We visit each node of the binary tree at most once.
- **Space Complexity**: $\mathcal{O}(H)$ — Where $H$ is the height of the tree, representing the recursion stack depth. In the worst case (skewed tree), the height is $N$. In the best case (balanced tree), the height is $\log N$.
