# Binary Tree Postorder Traversal

![Easy](https://img.shields.io/badge/Difficulty-Easy-green)
🔗 **[Problem Link](https://leetcode.com/problems/binary-tree-postorder-traversal/)**

---

## 📝 Problem Description

Given the `root` of a binary tree, return *the postorder traversal of its nodes' values*.

---

## 💡 Intuition & Core Logic

Postorder traversal visits nodes in the following recursive order:
1. **Left Subtree**: Recursively traverse the left subtree first.
2. **Right Subtree**: Recursively traverse the right subtree.
3. **Root Node**: Visit/process the current root node last.

### Recursive Approach
- We define a helper function `postorder(root, result)` that carries out the traversal.
- If the current node is `nullptr` (base case), we simply return.
- We call the helper on `root->left`.
- We call the helper on `root->right`.
- We push the current node's value (`root->val`) into our `result` vector.

---

## 🔄 Step-by-Step Dry Run

Consider the following Binary Tree:
```text
       1
        \
         2
        /
       3
```

1. **Start traversal at root (`1`)**:
   - Call `postorder(1)`.
   - Traverse left child of `1` (`nullptr`): returns immediately.
   - Traverse right child of `1` (`2`): Call `postorder(2)`.

2. **At node `2`**:
   - Traverse left child of `2` (`3`): Call `postorder(3)`.

3. **At node `3`**:
   - Traverse left child of `3` (`nullptr`): returns immediately.
   - Traverse right child of `3` (`nullptr`): returns immediately.
   - Process root `3`: `result = [3]`.
   - Return back to node `2`.

4. **Back at node `2`**:
   - Traverse right child of `2` (`nullptr`): returns immediately.
   - Process root `2`: `result = [3, 2]`.
   - Return back to node `1`.

5. **Back at node `1`**:
   - Process root `1`: `result = [3, 2, 1]`.

6. **Traversal complete**:
   - `result = [3, 2, 1]`.

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
    void postorder(TreeNode* root, vector<int> &result){
        if(root == nullptr)
            return;
        postorder(root->left, result);
        postorder(root->right, result);
        result.push_back(root->val);
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        postorder(root, result);
        return result;
    }
};
```

---

## 📊 Complexity Analysis

- **Time Complexity**: $\mathcal{O}(N)$ — Where $N$ is the number of nodes in the binary tree. We visit each node exactly once.
- **Space Complexity**: $\mathcal{O}(N)$ (Worst Case) / $\mathcal{O}(\log N)$ (Average Case) — For the recursive call stack. In the worst case (skewed tree), the depth of the call stack can be $N$. In the average case (balanced tree), the depth is $\mathcal{O}(\log N)$.
