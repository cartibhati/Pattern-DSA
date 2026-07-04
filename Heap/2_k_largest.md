# Kth Largest Element in an Array (LeetCode 215)

![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow)
🔗 **[Problem Link](https://leetcode.com/problems/kth-largest-element-in-an-array/)**

---

## 📝 Problem Description

Given an integer array `nums` and an integer `k`, return the `k`-th largest element in the array.

Note that it is the `k`-th largest element in the sorted order, not the `k`-th distinct element.

---

## 💡 Intuition & Core Logic

To find the `k`-th largest element, we can use a **Min-Heap** (represented by `priority_queue<int, vector<int>, greater<int>>` in C++).

1. **Maintain a Min-Heap of size k**:
   - Push the first `k` elements of the array into the Min-Heap. The smallest of these `k` elements will sit at the top of the heap.
2. **Process remaining elements**:
   - For each subsequent element in the array (from index `k` to `n-1`):
     - If the element is larger than the top of the heap (`nums[i] > pq.top()`), it means the current top cannot be part of the `k` largest elements.
     - So, we pop the top element from the heap and push `nums[i]`.
     - If the element is smaller than or equal to the top, we ignore it.
3. **Result**:
   - After processing all elements, the heap will contain the `k` largest elements of the array.
   - The top of the Min-Heap is the smallest among these `k` largest elements, which is exactly the `k`-th largest element in the array. Return `pq.top()`.

---

## 🔄 Step-by-Step Dry Run

For `nums = [3, 2, 1, 5, 6, 4]`, `k = 2`.

1. **Initialize Min-Heap with first `k = 2` elements**:
   - Push `3` -> `pq = [3]`
   - Push `2` -> `pq = [2, 3]` (top is `2`)

2. **Process remaining elements**:
   - `i = 2`: `nums[2] = 1`.
     - Is `nums[2] > pq.top()`? No, `1 <= 2`. Ignore.
     - `pq = [2, 3]` (top is `2`).
   - `i = 3`: `nums[3] = 5`.
     - Is `nums[3] > pq.top()`? Yes, `5 > 2`.
     - Pop `2`. Push `5`.
     - `pq = [3, 5]` (top is `3`).
   - `i = 4`: `nums[4] = 6`.
     - Is `nums[4] > pq.top()`? Yes, `6 > 3`.
     - Pop `3`. Push `6`.
     - `pq = [5, 6]` (top is `5`).
   - `i = 5`: `nums[5] = 4`.
     - Is `nums[5] > pq.top()`? No, `4 <= 5`. Ignore.
     - `pq = [5, 6]` (top is `5`).

3. **Return Result**:
   - Return `pq.top()` which is `5`. (The sorted array is `[1, 2, 3, 4, 5, 6]`, the 2nd largest is indeed `5`).

---

## 💻 C++ Working Code

```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < k; i++) {
            pq.push(nums[i]);
        }

        for (int i = k; i < n; i++) {
            if (nums[i] <= pq.top())
                continue;

            pq.pop();
            pq.push(nums[i]);
        }
        return pq.top();
    }
};
```

---

## 📊 Complexity Analysis

- **Time Complexity**: `O(N log k)` — Pushing and popping from a heap of size `k` takes `O(log k)` time. We perform this operation at most `N` times.
- **Space Complexity**: `O(k)` — The Min-Heap stores at most `k` elements at any given time.
