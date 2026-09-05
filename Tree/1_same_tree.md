# Same Tree

![Easy](https://img.shields.io/badge/Difficulty-Easy-green)
🔗 **[Problem Link](https://leetcode.com/problems/same-tree/)**

---

## 📝 Problem Description

Given the roots of two binary trees `p` and `q`, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

---

## 💡 Intuition & Core Logic

We can compare two binary trees recursively by traversing both trees simultaneously using Depth-First Search (DFS).

### Recursive Approach
1. **Base Cases**:
   - If both `p` and `q` are `nullptr`, both trees reached the end simultaneously along this branch $\rightarrow$ return `true`.
   - If only one of `p` or `q` is `nullptr` while the other is not, the tree structures differ $\rightarrow$ return `false`.
   - If `p->val != q->val`, the values at the current corresponding nodes differ $\rightarrow$ return `false`.

2. **Recursive Traversal**:
   - Recursively check if both left and right subtrees are identical $\rightarrow$ return `isSameTree(p->left, q->left) && isSameTree(p->right, q->right)`.

---

## 🔄 Step-by-Step Dry Run

Consider two binary trees:

**Tree 1 (`p`)**:
```text
    1
   / \
  2   3
```

**Tree 2 (`q`)**:
```text
    1
   / \
  2   3
```

1. **Start at Root Nodes (`p = 1`, `q = 1`)**:
   - Both non-null, values equal (`1 == 1`).
   - Recurse on left subtree: `isSameTree(2, 2)`.

2. **At Left Children (`p = 2`, `q = 2`)**:
   - Both non-null, values equal (`2 == 2`).
   - Recurse left child: `isSameTree(nullptr, nullptr)` $\rightarrow$ returns `true`.
   - Recurse right child: `isSameTree(nullptr, nullptr)` $\rightarrow$ returns `true`.
   - Returns `true && true = true` back to root node `1`.

3. **At Right Children (`p = 3`, `q = 3`)**:
   - Both non-null, values equal (`3 == 3`).
   - Recurse left child: `isSameTree(nullptr, nullptr)` $\rightarrow$ returns `true`.
   - Recurse right child: `isSameTree(nullptr, nullptr)` $\rightarrow$ returns `true`.
   - Returns `true && true = true` back to root node `1`.

4. **Final Return at Root**:
   - `r1 = true`, `r2 = true`.
   - Returns `true && true = true`. Both trees are identical!

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL)
        return true;
        if(p==NULL || q==NULL)
        return false;
        if(p->val!=q->val)
        return false;

        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
};
```

---

## 📊 Complexity Analysis

- **Time Complexity**: $\mathcal{O}(N)$ — Where $N$ is the minimum number of nodes in the two trees. In the worst case, we visit each node once.
- **Space Complexity**: $\mathcal{O}(H)$ — Where $H$ is the height of the tree, representing the maximum call stack depth. In a skewed tree, $H = \mathcal{O}(N)$; in a balanced tree, $H = \mathcal{O}(\log N)$.
