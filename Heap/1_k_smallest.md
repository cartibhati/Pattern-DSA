# Kth Smallest Element (GFG)

![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow)
🔗 **[Problem Link](https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1)**

---

## 📝 Problem Description

Given an array `arr[]` and an integer `k` where `k` is smaller than the size of the array, the task is to find the `k`-th smallest element in the given array. It is given that all array elements are distinct.

---

## 💡 Intuition & Core Logic

We can solve this problem efficiently using a **Max-Heap** (represented by `std::priority_queue` in C++).

1. **Maintain a Max-Heap of size k**:
   - Push the first `k` elements of the array into the Max-Heap. The largest of these `k` elements will sit at the top of the heap.
2. **Process remaining elements**:
   - For each subsequent element in the array (from index `k` to `n-1`):
     - If the element is smaller than the top of the heap (`arr[i] < pq.top()`), it means the current top cannot be part of the `k` smallest elements.
     - So, we pop the top element from the heap and push `arr[i]`.
     - If the element is greater than or equal to the top, we simply ignore it since it cannot be one of the `k` smallest elements.
3. **Result**:
   - After processing all elements, the heap will contain the `k` smallest elements of the array.
   - The top of the Max-Heap is the largest among these `k` smallest elements, which is exactly the `k`-th smallest element in the array. Return `pq.top()`.

---

## 🔄 Step-by-Step Dry Run

For `arr = [7, 10, 4, 3, 20, 15]`, `k = 3`.

1. **Initialize Max-Heap with first `k = 3` elements**:
   - Push `7` -> `pq = [7]`
   - Push `10` -> `pq = [10, 7]` (top is `10`)
   - Push `4` -> `pq = [10, 7, 4]` (top is `10`)

2. **Process remaining elements**:
   - `i = 3`: `arr[3] = 3`.
     - Is `arr[3] < pq.top()`? Yes, `3 < 10`.
     - Pop `10`. Push `3`.
     - `pq = [7, 4, 3]` (top is `7`).
   - `i = 4`: `arr[4] = 20`.
     - Is `arr[4] < pq.top()`? No, `20 >= 7`. Ignore.
     - `pq = [7, 4, 3]` (top is `7`).
   - `i = 5`: `arr[5] = 15`.
     - Is `arr[5] < pq.top()`? No, `15 >= 7`. Ignore.
     - `pq = [7, 4, 3]` (top is `7`).

3. **Return Result**:
   - Return `pq.top()` which is `7`. (The sorted array is `[3, 4, 7, 10, 15, 20]`, the 3rd smallest is indeed `7`).

---

## 💻 C++ Working Code

```cpp
class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        int n = arr.size();
        priority_queue<int> pq;
        for (int i = 0; i < k; i++) {
            pq.push(arr[i]);
        }
        for (int i = k; i < n; i++) {
            if (arr[i] >= pq.top())
                continue;
            
            pq.pop();
            pq.push(arr[i]);
        }
        return pq.top();
    }
};
```

---

## 📊 Complexity Analysis

- **Time Complexity**: `O(N log k)` — Pushing and popping from a heap of size `k` takes `O(log k)` time. We perform this operation at most `N` times.
- **Space Complexity**: `O(k)` — The Max-Heap stores at most `k` elements at any given time.
