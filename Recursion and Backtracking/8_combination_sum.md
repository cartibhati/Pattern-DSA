# Combination Sum

![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow)
🔗 **[Problem Link](https://leetcode.com/problems/combination-sum/)**

---

## 📝 Problem Description

Given an array of **distinct** integers `candidates` and a `target` integer `target`, return a list of all **unique combinations** of `candidates` where the chosen numbers sum to `target`. You may return the combinations in **any order**.

The **same** number may be chosen from `candidates` an **unlimited number of times**. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to `target` is less than `150` combinations for the given input.

---

## 💡 Intuition & Core Logic

This problem can be solved using **Backtracking / Recursion** with a decision-tree structure:
At each index `idx`, we have two primary choices:
1. **Not Pick**: Skip the current candidate and move to the next index (`idx + 1`).
2. **Pick**: If the current candidate `candidates[idx]` can fit within the target (i.e. does not exceed the remaining target), we add it to our running combination (`diary`). Since we can reuse the same candidate an unlimited number of times, we recursively call the function staying at the **same index** `idx`. After the recursive call returns, we backtrack by removing the last added candidate (`diary.pop_back()`).

### Base Cases:
- **Success**: If the running `sum == target`, we have found a valid combination. We add `diary` to the results and return.
- **Pruning / Bound Conditions**: If the index `idx == n` (out of bounds) or the running `sum > target`, it is impossible to form a valid combination. We prune the search and return.

---

## 🔄 Step-by-Step Dry Run

For `candidates = [2, 3, 6, 7]` and `target = 7`:

- Call `fun(candidates, n=4, idx=0, diary=[], sum=0, res, target=7)`:
  - **Path 1 (Pick 2)**: `diary = [2]`, `sum = 2`, call with `idx = 0`
    - **Pick 2 again**: `diary = [2, 2]`, `sum = 4`, call with `idx = 0`
      - **Pick 2 again**: `diary = [2, 2, 2]`, `sum = 6`, call with `idx = 0`
        - **Pick 2 again**: `diary = [2, 2, 2, 2]`, `sum = 8 > 7` (Returns, Backtracks)
        - **Not Pick 2**: Move to `idx = 1` (value 3).
          - **Pick 3**: `diary = [2, 2, 2, 3]`, `sum = 9 > 7` (Returns, Backtracks)
          - **Not Pick 3**: Move to `idx = 2` (value 6)... Eventually all paths returning/pruning.
      - **Not Pick 2**: Move to `idx = 1` (value 3).
        - **Pick 3**: `diary = [2, 2, 3]`, `sum = 7 == 7` (**Valid Combination found!** Add `[2, 2, 3]` to results. Return, Backtrack).
  - **Path 2 (Not Pick 2 starting out)**: Move to `idx = 1` (value 3).
    - ...
  - **Path 3 (Not Pick 2, 3, 6 starting out)**: Move to `idx = 3` (value 7).
    - **Pick 7**: `diary = [7]`, `sum = 7 == 7` (**Valid Combination found!** Add `[7]` to results. Return, Backtrack).

Final Result: `[[2, 2, 3], [7]]`.

---

## 💻 C++ Working Code

```cpp
class Solution {
public:
    void fun(vector<int>& a, int n, int idx, vector<int>& diary, int sum,
             vector<vector<int>>& res, int target) {
        
        if (sum == target) {
            res.push_back(diary);
            return;
        }
        
        if (idx == n || sum > target) return;

        // Not pick
        fun(a, n, idx + 1, diary, sum, res, target);

        // Pick (stay at same index because unlimited use allowed)
        diary.push_back(a[idx]);
        fun(a, n, idx, diary, sum + a[idx], res, target);
        diary.pop_back();
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> diary;

        fun(candidates, candidates.size(), 0, diary, 0, res, target);

        return res;
    }
};
```

---

## 📊 Complexity Analysis

- **Time Complexity**: $\mathcal{O}(2^T \cdot K)$ where $T$ is the target value and $K$ is the average length of a combination. In the worst case (e.g. candidate value is 1), the recursion depth reaches $T$. At each recursive step, we make 2 choices (pick or not pick), leading to at most $\mathcal{O}(2^T)$ recursive states. When a combination is valid, copying it to the results list takes $\mathcal{O}(K)$ time.
- **Space Complexity**: $\mathcal{O}(T)$ — The depth of the recursion tree can go up to $T$ in the worst case (when target is recursively reduced by the smallest candidate). The temporary array `diary` also takes at most $\mathcal{O}(T)$ space.
