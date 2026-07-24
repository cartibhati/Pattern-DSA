# Check Completeness of a Binary Tree

![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow)
🔗 **[Problem Link](https://leetcode.com/problems/check-completeness-of-a-binary-tree/)**

---

## 📝 Problem Description

Given the `root` of a binary tree, determine if it is a **complete binary tree**.

In a complete binary tree, every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and $2^h$ nodes inclusive at the last level $h$.

---

## 💡 Intuition & Core Logic

A complete binary tree has **no gaps** when traversed level by level (from left to right).

If we perform a Breadth-First Search (BFS) / Level-Order Traversal using a queue:
1. We push all nodes (including `nullptr` children) to the queue.
2. Once we encounter a `nullptr` node, any node popped after it must also be `nullptr`.
3. If we encounter a non-null node *after* we have already seen a `nullptr` node, it means there is a gap in the tree structure (which violates the completeness property).

### BFS Approach
1. Initialize a queue `q` containing the `root` node.
2. Maintain a boolean flag `nullfound = false`.
3. Loop while `q` is not empty:
   - Pop the front node `t`.
   - If `t` is `nullptr`, set `nullfound = true`.
   - If `t` is not `nullptr`:
     - If `nullfound` is `true`, we have encountered a non-null node after a `nullptr` node $\rightarrow$ return `false`.
     - Otherwise, push `t->left` and `t->right` to the queue (even if they are `nullptr`).
4. If the traversal completes without returning `false`, return `true`.

---

## 🔄 Step-by-Step Dry Run

### Example 1: Complete Binary Tree

```text
        1
       / \
      2   3
     / \  /
    4   5 6
```

- **Queue Initialization**: `q = [1]`
- **Step 1**: Pop `1`. `1 != nullptr`. Push `2` and `3`. `q = [2, 3]`
- **Step 2**: Pop `2`. `2 != nullptr`. Push `4` and `5`. `q = [3, 4, 5]`
- **Step 3**: Pop `3`. `3 != nullptr`. Push `6` and `nullptr`. `q = [4, 5, 6, nullptr]`
- **Step 4**: Pop `4`. `4 != nullptr`. Push `nullptr` and `nullptr`. `q = [5, 6, nullptr, nullptr, nullptr]`
- **Step 5**: Pop `5`. `5 != nullptr`. Push `nullptr` and `nullptr`. `q = [6, nullptr, nullptr, nullptr, nullptr, nullptr]`
- **Step 6**: Pop `6`. `6 != nullptr`. Push `nullptr` and `nullptr`. `q = [nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr]`
- **Step 7**: Pop `nullptr`. `nullfound = true`.
- **Steps 8+**: All subsequent pops are `nullptr` nodes. No non-null nodes are encountered after `nullfound` becomes `true`.
- **Return**: `true`.

---

### Example 2: Incomplete Binary Tree

```text
        1
       / \
      2   3
     /     \
    4       6
```

- **Queue Initialization**: `q = [1]`
- **Step 1**: Pop `1`. `1 != nullptr`. Push `2` and `3`. `q = [2, 3]`
- **Step 2**: Pop `2`. `2 != nullptr`. Push `4` and `nullptr`. `q = [3, 4, nullptr]`
- **Step 3**: Pop `3`. `3 != nullptr`. Push `nullptr` and `6`. `q = [4, nullptr, nullptr, 6]`
- **Step 4**: Pop `4`. `4 != nullptr`. Push `nullptr` and `nullptr`. `q = [nullptr, nullptr, 6, nullptr, nullptr]`
- **Step 5**: Pop `nullptr`. `nullfound = true`. `q = [nullptr, 6, nullptr, nullptr]`
- **Step 6**: Pop `nullptr`. `nullfound = true`. `q = [6, nullptr, nullptr]`
- **Step 7**: Pop `6`. `6 != nullptr`, but `nullfound == true` $\rightarrow$ Return `false`.

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
    bool isCompleteTree(TreeNode* root) {
        if(root==NULL)
        return true;

        bool nullfound= false;

        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* t=q.front();
            q.pop();
            if(t==NULL)
            nullfound=true;
            else{
                if(nullfound)
                return false;
                q.push(t->left);
                q.push(t->right);
            }
        }
        return true;
    }
};
```

---

## 📊 Complexity Analysis

- **Time Complexity**: $\mathcal{O}(N)$ — Where $N$ is the number of nodes in the binary tree. We visit each node and its children exactly once.
- **Space Complexity**: $\mathcal{O}(N)$ — Where $N$ is the number of nodes. In the worst case, the queue can store all nodes at the last level of the tree, which is approximately $N/2$ nodes.
