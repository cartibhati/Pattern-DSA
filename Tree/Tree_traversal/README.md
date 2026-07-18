# 🌲 Tree Traversal Pattern

Tree traversal refers to the process of visiting all nodes of a tree data structure (typically a Binary Tree) in a specific systematic order. These traversals are categorized into Depth-First Search (DFS) and Breadth-First Search (BFS).

---

## 📝 Concept Cheatsheet

### Depth-First Search (DFS)
DFS traversals explore as deep as possible along each branch before backtracking. They are naturally implemented using recursion (which uses the call stack) or iteratively using an explicit stack.

#### 1. Inorder Traversal (Left ➡️ Root ➡️ Right)
Used in Binary Search Trees (BST) to retrieve elements in sorted order.
```cpp
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    // Process root
    inorder(root->right);
}
```

#### 2. Preorder Traversal (Root ➡️ Left ➡️ Right)
Useful for creating a copy of the tree or prefix expression evaluation.
```cpp
void preorder(TreeNode* root) {
    if (!root) return;
    // Process root
    preorder(root->left);
    preorder(root->right);
}
```

#### 3. Postorder Traversal (Left ➡️ Right ➡️ Root)
Used for deleting a tree or postfix expression evaluation (processing children before the root).
```cpp
void postorder(TreeNode* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    // Process root
}
```

---

## 📈 Problem Progression (Easy to Hard)

| # | Problem Title | Difficulty | Source & Link | C++ Solution | Detailed Explanation |
|---|---|---|---|---|---|
| 1 | **Binary Tree Inorder Traversal** | ![Easy](https://img.shields.io/badge/Difficulty-Easy-green) | [Problem Link](https://leetcode.com/problems/binary-tree-inorder-traversal/) | [`1_inorder.cpp`](./1_inorder.cpp) | [Explanation & Dry Run](1_inorder.md) |
| 2 | **Binary Tree Preorder Traversal** | ![Easy](https://img.shields.io/badge/Difficulty-Easy-green) | [Problem Link](https://leetcode.com/problems/binary-tree-preorder-traversal/) | [`2_preorder.cpp`](./2_preorder.cpp) | [Explanation & Dry Run](2_preorder.md) |
| 3 | **Binary Tree Postorder Traversal** | ![Easy](https://img.shields.io/badge/Difficulty-Easy-green) | [Problem Link](https://leetcode.com/problems/binary-tree-postorder-traversal/) | [`3_postorder.cpp`](./3_postorder.cpp) | [Explanation & Dry Run](3_postorder.md) |

---

*Click on any problem's explanation link to read the step-by-step dry run, logic, and complexity analysis!*
