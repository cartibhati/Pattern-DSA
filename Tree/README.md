# 🌲 Tree Pattern

The Tree pattern covers essential algorithms and techniques for binary trees, binary search trees, and general trees, including structural comparisons, depth-first search (DFS), tree modifications, and traversals.

---

## 📝 Concept Cheatsheet

### Comparing Two Trees (DFS Recursion)
To check if two trees are identical in structure and node values:
1. **Base cases**: Both `nullptr` $\rightarrow$ `true`. One `nullptr` $\rightarrow$ `false`.
2. **Value check**: `p->val != q->val` $\rightarrow$ `false`.
3. **Recursive call**: Recurse simultaneously on left subtrees (`isSameTree(p->left, q->left)`) and right subtrees (`isSameTree(p->right, q->right)`).

---

## 📈 Problem Progression (Easy to Hard)

| # | Problem Title | Difficulty | Source & Link | C++ Solution | Detailed Explanation |
|---|---|---|---|---|---|
| 1 | **Same Tree** | ![Easy](https://img.shields.io/badge/Difficulty-Easy-green) | [Problem Link](https://leetcode.com/problems/same-tree/) | [`1_same_tree.cpp`](./1_same_tree.cpp) | [Explanation & Dry Run](1_same_tree.md) |
| 2 | **Symmetric Tree** | ![Easy](https://img.shields.io/badge/Difficulty-Easy-green) | [Problem Link](https://leetcode.com/problems/symmetric-tree/) | [`2_symmetric_tree.cpp`](./2_symmetric_tree.cpp) | [Explanation & Dry Run](2_symmetric_tree.md) |
| 3 | **Invert Binary Tree** | ![Easy](https://img.shields.io/badge/Difficulty-Easy-green) | [Problem Link](https://leetcode.com/problems/invert-binary-tree/) | [`3_Invert_tree.cpp`](./3_Invert_tree.cpp) | [Explanation & Dry Run](3_Invert_tree.md) |
| 4 | **Lowest Common Ancestor** | ![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow) | [Problem Link](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/) | [`4_lowest_common_ancestor.cpp`](./4_lowest_common_ancestor.cpp) | [Explanation & Dry Run](4_lowest_common_ancestor.md) |
| 5 | **Search in a BST** | ![Easy](https://img.shields.io/badge/Difficulty-Easy-green) | [Problem Link](https://leetcode.com/problems/search-in-a-binary-search-tree/) | [`5_search_in_BST.cpp`](./5_search_in_BST.cpp) | [Explanation & Dry Run](5_search_in_BST.md) |
| 6 | **LCA in a BST** | ![Easy](https://img.shields.io/badge/Difficulty-Easy-green) | [Problem Link](https://www.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1) | [`6_lca_in_BST.cpp`](./6_lca_in_BST.cpp) | [Explanation & Dry Run](6_lca_in_BST.md) |
| 7 | **Two Sum IV - Input is a BST** | ![Easy](https://img.shields.io/badge/Difficulty-Easy-green) | [Problem Link](https://leetcode.com/problems/two-sum-iv-input-is-a-bst/) | [`7_two_sum_BST.cpp`](./7_two_sum_BST.cpp) | [Explanation & Dry Run](7_two_sum_BST.md) |
| 8 | **Diameter of Binary Tree** | ![Easy](https://img.shields.io/badge/Difficulty-Easy-green) | [Problem Link](https://leetcode.com/problems/diameter-of-binary-tree/) | [`8_diameter_of_binary_tree.cpp`](./8_diameter_of_binary_tree.cpp) | [Explanation & Dry Run](8_diameter_of_binary_tree.md) |
| 9 | **Check Completeness of a Binary Tree** | ![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow) | [Problem Link](https://leetcode.com/problems/check-completeness-of-a-binary-tree/) | [`9_completeness_of_binary_tree.cpp`](./9_completeness_of_binary_tree.cpp) | [Explanation & Dry Run](9_completeness_of_binary_tree.md) |


---

## 📂 Sub-Patterns

- **[Tree Traversal](./Tree_traversal)**: Inorder, Preorder, Postorder, Level Order, and Zigzag Traversal.

---

*Click on any problem's explanation link to read the step-by-step dry run, logic, and complexity analysis!*
