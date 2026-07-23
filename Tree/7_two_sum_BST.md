# Two Sum IV - Input is a BST

![Easy](https://img.shields.io/badge/Difficulty-Easy-green)
🔗 **[Problem Link](https://leetcode.com/problems/two-sum-iv-input-is-a-bst/)**

---

## 📝 Problem Description

Given the root of a binary search tree and a target number `k`, return `true` if there exist two elements in the BST such that their sum is equal to the given target.

---

## 💡 Intuition & Core Logic

A naive approach is to store the inorder traversal of the BST in an array (which is sorted) and then use the two-pointer technique to find if a pair exists. While this is simple, it requires $\mathcal{O}(N)$ extra space to store the node values.

We can optimize the space complexity to $\mathcal{O}(H)$ (where $H$ is the height of the tree) by implementing a **BST Iterator** (controlled inorder traversal) in both directions:
1. **Ascending Iterator (`getsmall`)**: Acts as the left pointer ($i$), yielding values in increasing order (standard inorder traversal: Left $\rightarrow$ Node $\rightarrow$ Right).
2. **Descending Iterator (`getbig`)**: Acts as the right pointer ($j$), yielding values in decreasing order (reverse inorder traversal: Right $\rightarrow$ Node $\rightarrow$ Left).

### Algorithm:
1. Initialize two stacks: `asc` for ascending traversal and `desc` for descending traversal.
2. Push all left children starting from the root into `asc` to point to the smallest element.
3. Push all right children starting from the root into `desc` to point to the largest element.
4. Retrieve the first elements `i = getsmall()` and `j = getbig()`.
5. While `i != j` and `i->val <= j->val`:
   - Calculate `sum = i->val + j->val`.
   - If `sum == k`, return `true`.
   - If `sum < k`, we need a larger sum, so we advance the left pointer: `i = getsmall()`.
   - If `sum > k`, we need a smaller sum, so we retreat the right pointer: `j = getbig()`.
6. If no such pair is found, return `false`.

---

## 🔄 Step-by-Step Dry Run

Consider the following BST:

```text
        5
       / \
      3   6
     / \   \
    2   4   7
```

We want to find if there is a pair that sums to **`k = 9`**.

1. **Initialize Stacks**:
   - `asc` (path to leftmost): `[5, 3, 2]` (Top is `2`)
   - `desc` (path to rightmost): `[5, 6, 7]` (Top is `7`)

2. **Retrieve Initial Nodes**:
   - `i = getsmall()`: Pops `2`. Since `2` has no right child, `asc` becomes `[5, 3]`. `i` points to node `2`.
   - `j = getbig()`: Pops `7`. Since `7` has no left child, `desc` becomes `[5, 6]`. `j` points to node `7`.

3. **First Iteration**:
   - `i->val = 2`, `j->val = 7`.
   - `sum = 2 + 7 = 9`.
   - Since `sum == k` (`9 == 9`), we return `true` immediately.

---

## 💻 C++ Working Code

```cpp
class Solution {
public:
    stack<TreeNode*> asc;
    stack<TreeNode*> desc;

    TreeNode* getsmall() {
        if (asc.empty())
            return nullptr;

        TreeNode* small = asc.top();
        asc.pop();

        TreeNode* rightchild = small->right;
        while (rightchild) {
            asc.push(rightchild);
            rightchild = rightchild->left;
        }

        return small;
    }

    TreeNode* getbig() {
        if (desc.empty())
            return nullptr;

        TreeNode* big = desc.top();
        desc.pop();

        TreeNode* leftchild = big->left;
        while (leftchild) {
            desc.push(leftchild);
            leftchild = leftchild->right;
        }

        return big;
    }

    bool findTarget(TreeNode* root, int k) {
        if (root == nullptr)
            return false;

        TreeNode* t = root;

        while (t) {
            asc.push(t);
            t = t->left;
        }

        t = root;

        while (t) {
            desc.push(t);
            t = t->right;
        }

        TreeNode* i = getsmall();
        TreeNode* j = getbig();

        while (i && j && i != j && i->val <= j->val) {
            int sum = i->val + j->val;

            if (sum == k)
                return true;

            if (sum > k)
                j = getbig();
            else
                i = getsmall();
        }

        return false;
    }
};
```

---

## 📊 Complexity Analysis

- **Time Complexity**: $\mathcal{O}(N)$ — In the worst case, we might traverse almost the entire tree, checking multiple pairs. However, each node is pushed and popped from the stacks at most once, which ensures that the amortized time complexity for each step is $\mathcal{O}(1)$.
- **Space Complexity**: $\mathcal{O}(H)$ — Where $H$ is the height of the BST. We store the path to the current node in the stacks, which requires $\mathcal{O}(\log N)$ space for a balanced BST and $\mathcal{O}(N)$ space in the worst case (skewed tree). This is a significant improvement over the $\mathcal{O}(N)$ space needed to store the full traversal.
