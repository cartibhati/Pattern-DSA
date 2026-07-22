# Lowest Common Ancestor in a BST

![Easy](https://img.shields.io/badge/Difficulty-Easy-green)
🔗 **[Problem Link](https://www.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1)**

---

## 📝 Problem Description

Given a Binary Search Tree (with all values unique) and two node values `n1` and `n2`. Find the Lowest Common Ancestor (LCA) of the two nodes in the BST.

According to the definition of LCA: “The lowest common ancestor is defined between two nodes `n1` and `n2` as the lowest node in `T` that has both `n1` and `n2` as descendants (where we allow a node to be a descendant of itself).”

---

## 💡 Intuition & Core Logic

In a Binary Search Tree (BST), the nodes are ordered: left children have values smaller than the parent, and right children have values larger than the parent.

We can find the LCA of `n1` and `n2` by traversing the tree starting from the root:
1. If both `n1` and `n2` are smaller than the current root's value, then their LCA must lie in the left subtree. Therefore, we recurse on the left child.
2. If both `n1` and `n2` are greater than the current root's value, then their LCA must lie in the right subtree. Therefore, we recurse on the right child.
3. If one value is smaller and the other is greater (or if one of them is equal to the current node's value), then the current node is the split point, meaning it is the Lowest Common Ancestor. We return the current node.

---

## 🔄 Step-by-Step Dry Run

Consider the following BST:

```text
        5
       / \
      4   6
     /     \
    3       7
             \
              8
```

We want to find the LCA of **`n1 = 7`** and **`n2 = 8`**.

1. **Start at Root Node `5`**:
   - `root->data = 5`.
   - Since both `n1 = 7 > 5` and `n2 = 8 > 5`, their LCA must lie in the right subtree.
   - Recurse right: `LCA(root->right, n1, n2)` (which calls node `6`).

2. **At Node `6`**:
   - `root->data = 6`.
   - Since both `7 > 6` and `8 > 6`, recurse right: `LCA(root->right, n1, n2)` (which calls node `7`).

3. **At Node `7`**:
   - `root->data = 7`.
   - Here, `n1->data = 7` is equal to `root->data`, but `n2->data = 8 > 7`.
   - The condition `root->data < n1->data && root->data < n2->data` is false (since `7` is not `< 7`).
   - The condition `root->data > n1->data && root->data > n2->data` is also false.
   - So, we return `root` (node `7`).

**Final Result**: LCA is Node `7`.

---

## 💻 C++ Working Code

```cpp
/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
public:
    Node* LCA(Node* root, Node* n1, Node* n2) {
        if(root == NULL)
            return NULL;

        if(root->data > n1->data && root->data > n2->data)
            return LCA(root->left, n1, n2);

        if(root->data < n1->data && root->data < n2->data)
            return LCA(root->right, n1, n2);

        return root;
    }
};
```

---

## 📊 Complexity Analysis

- **Time Complexity**: $\mathcal{O}(H)$ — Where $H$ is the height of the BST. In the worst case (skewed tree), we might traverse $N$ nodes $\rightarrow \mathcal{O}(N)$. In a balanced BST, the height is $\mathcal{O}(\log N)$, making the search very efficient.
- **Space Complexity**: $\mathcal{O}(H)$ — Representing the recursion call stack depth. Similar to time complexity, this is $\mathcal{O}(\log N)$ for a balanced tree and $\mathcal{O}(N)$ for a skewed tree.
