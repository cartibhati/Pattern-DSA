# Binary Tree Level Order Traversal

![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow)
🔗 **[Problem Link](https://leetcode.com/problems/binary-tree-level-order-traversal/)**

---

## 📝 Problem Description

Given the `root` of a binary tree, return *the level order traversal of its nodes' values*. (i.e., from left to right, level by level).

---

## 💡 Intuition & Core Logic

Level order traversal is a Breadth-First Search (BFS) algorithm. We traverse the tree level by level, starting from the root (Level 0), then visiting all nodes at Level 1, then Level 2, and so on.

### BFS Approach using Queue
1. **Base Case**: If the tree is empty (`root == nullptr`), return an empty list `{}`.
2. **Initialization**: Initialize a FIFO Queue and push the `root` node into it.
3. **Traversal**:
   - While the queue is not empty, calculate the size of the queue (`lvlsize`). This represents the number of nodes at the current level.
   - Iterate `lvlsize` times to process all nodes at this level.
   - For each node:
     - Pop it from the queue and record its value in a temporary level list `temp`.
     - Push its left child and right child (if they exist) to the queue for the next level.
   - Append the level list `temp` to the final result list `res`.
4. Return `res`.

---

## 🔄 Step-by-Step Dry Run

Consider the following Binary Tree:
```text
        3
       / \
      9  20
        /  \
       15   7
```

1. **Initialization**:
   - `root = 3`
   - Queue `q = [3]`
   - Result `res = []`

2. **Iteration 1 (Level 0)**:
   - `lvlsize = 1` (Queue has `[3]`)
   - `temp = []`
   - Pop `3`: `temp = [3]`. Push children of `3` (`9` and `20`) to `q`.
   - `q = [9, 20]`
   - `res = [[3]]`

3. **Iteration 2 (Level 1)**:
   - `lvlsize = 2` (Queue has `[9, 20]`)
   - `temp = []`
   - Pop `9`: `temp = [9]`. Push children of `9` (`nullptr`, `nullptr`) -> nothing.
   - Pop `20`: `temp = [9, 20]`. Push children of `20` (`15` and `7`) to `q`.
   - `q = [15, 7]`
   - `res = [[3], [9, 20]]`

4. **Iteration 3 (Level 2)**:
   - `lvlsize = 2` (Queue has `[15, 7]`)
   - `temp = []`
   - Pop `15`: `temp = [15]`. Push children of `15` -> nothing.
   - Pop `7`: `temp = [15, 7]`. Push children of `7` -> nothing.
   - `q = []`
   - `res = [[3], [9, 20], [15, 7]]`

5. **End**:
   - Queue is empty. Return `res`.

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr)
            return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> res;
        while (!q.empty()) {
            int lvlsize = q.size();
            vector<int> temp;
            while (lvlsize--) {
                TreeNode* t = q.front();
                q.pop();
                temp.push_back(t->val);

                if (t->left != nullptr)
                    q.push(t->left);
                if (t->right != nullptr)
                    q.push(t->right);
            }
            res.push_back(temp);
        }
        return res;
    }
};
```

---

## 📊 Complexity Analysis

- **Time Complexity**: $\mathcal{O}(N)$ — Where $N$ is the number of nodes in the binary tree. We visit each node exactly once.
- **Space Complexity**: $\mathcal{O}(N)$ — In the worst case (a complete binary tree), the queue will hold up to $\lceil N/2 \rceil$ nodes at the lowest level, requiring $\mathcal{O}(N)$ auxiliary space.
