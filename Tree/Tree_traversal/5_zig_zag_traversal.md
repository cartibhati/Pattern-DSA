# Binary Tree Zigzag Level Order Traversal

![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow)
🔗 **[Problem Link](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/)**

---

## 📝 Problem Description

Given the `root` of a binary tree, return *the zigzag level order traversal of its nodes' values*. (i.e., from left to right, then right to left for the next level, and alternate between).

---

## 💡 Intuition & Core Logic

This problem is a variation of the standard **Level Order Traversal (BFS)**. Instead of traversing every level from left to right, we alternate the direction of traversal for each level:
- **Even levels (0, 2, 4...)**: Left-to-right traversal.
- **Odd levels (1, 3, 5...)**: Right-to-left traversal.

### Algorithm
1. **Base Case**: If `root == nullptr`, return an empty list `{}`.
2. **Queue Setup**: Use a queue for standard BFS level order traversal. Push the `root`.
3. **Direction Flag**: Maintain a boolean flag `leftToRight = true` to keep track of the current level's direction.
4. **BFS Loop**:
   - For each level, determine the level size `lvlSize`.
   - Initialize a vector `temp` of size `lvlSize` to store the nodes of the current level.
   - Maintain index pointers `first = 0` and `last = lvlSize - 1` to fill the `temp` vector depending on the traversal direction:
     - If `leftToRight` is `true`, insert the node value at the index `first` and increment `first`.
     - If `leftToRight` is `false`, insert the node value at the index `last` and decrement `last`.
   - Push child nodes to the queue as usual (left child first, then right child).
   - After processing all nodes in the level, append `temp` to the result vector and toggle the flag: `leftToRight = !leftToRight`.

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
   - `root = 3`, Queue `q = [3]`, `leftToRight = true`, `res = []`.

2. **Level 0 (`lvlSize = 1`)**:
   - `temp` size is 1. `first = 0`, `last = 0`.
   - Pop `3` from `q`.
   - Since `leftToRight` is `true`, `temp[first] = 3` -> `temp = [3]`, `first` becomes 1.
   - Push children of `3` (`9` and `20`) to `q`.
   - `res = [[3]]`.
   - Toggle `leftToRight` to `false`.

3. **Level 1 (`lvlSize = 2`)**:
   - Queue `q = [9, 20]`.
   - `temp` size is 2. `first = 0`, `last = 1`.
   - **Process Node 9**:
     - Pop `9`.
     - Since `leftToRight` is `false`, `temp[last] = 9` -> `temp = [_, 9]`, `last` becomes 0.
     - Push children of `9` (none).
   - **Process Node 20**:
     - Pop `20`.
     - Since `leftToRight` is `false`, `temp[last] = 20` -> `temp = [20, 9]`, `last` becomes -1.
     - Push children of `20` (`15` and `7`) to `q`.
   - `res = [[3], [20, 9]]`.
   - Toggle `leftToRight` to `true`.

4. **Level 2 (`lvlSize = 2`)**:
   - Queue `q = [15, 7]`.
   - `temp` size is 2. `first = 0`, `last = 1`.
   - **Process Node 15**:
     - Pop `15`.
     - Since `leftToRight` is `true`, `temp[first] = 15` -> `temp = [15, _]`, `first` becomes 1.
   - **Process Node 7**:
     - Pop `7`.
     - Since `leftToRight` is `true`, `temp[first] = 7` -> `temp = [15, 7]`, `first` becomes 2.
   - `res = [[3], [20, 9], [15, 7]]`.
   - Toggle `leftToRight` to `false`.

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr)
            return {};

        queue<TreeNode*> q;
        q.push(root);

        vector<vector<int>> res;
        bool leftToRight = true;

        while (!q.empty()) {
            int lvlSize = q.size();
            vector<int> temp(lvlSize);

            int first = 0;
            int last = lvlSize - 1;

            while (lvlSize--) {
                TreeNode* t = q.front();
                q.pop();

                if (leftToRight) {
                    temp[first] = t->val;
                    first++;
                } else {
                    temp[last] = t->val;
                    last--;
                }

                if (t->left)
                    q.push(t->left);

                if (t->right)
                    q.push(t->right);
            }

            res.push_back(temp);
            leftToRight = !leftToRight;
        }

        return res;
    }
};
```

---

## 📊 Complexity Analysis

- **Time Complexity**: $\mathcal{O}(N)$ — We visit each node in the tree exactly once.
- **Space Complexity**: $\mathcal{O}(N)$ — The queue can hold at most $\lceil N/2 \rceil$ nodes at the lowest level of a complete binary tree.
