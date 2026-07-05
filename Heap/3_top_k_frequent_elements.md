# Top K Frequent Elements (LeetCode 347)

![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow)
🔗 **[Problem Link](https://leetcode.com/problems/top-k-frequent-elements/)**

---

## 📝 Problem Description

Given an integer array `nums` and an integer `k`, return the `k` most frequent elements. You may return the answer in **any order**.

---

## 💡 Intuition & Core Logic

To find the top `k` most frequent elements, we can combine a **frequency map** and a **Min-Heap** of size `k`.

1. **Calculate Frequencies**:
   - Use a hashmap `unordered_map<int, int> f` to count the occurrence of each number in the array.
2. **Maintain a Min-Heap of Size k**:
   - Store elements as `pair<int, int>` representing `{frequency, element}`.
   - Use a custom comparator `cmp` that prioritizes smaller frequencies (`a.first > b.first`). This creates a min-heap based on frequency, ensuring the element with the lowest frequency sits at the top.
   - Iterate through the frequency map:
     - Push the first `k` elements into the min-heap.
     - For subsequent elements: if the current element's frequency is larger than the top of the heap (`curr.first >= pq.top().first`), pop the minimum frequency element from the heap and push the current element.
3. **Result**:
   - The heap will contain exactly the `k` most frequent elements. Pop them and insert them into the result vector.

---

## 🔄 Step-by-Step Dry Run

For `nums = [1, 1, 1, 2, 2, 3]`, `k = 2`.

1. **Build Frequency Map**:
   - `1` -> 3
   - `2` -> 2
   - `3` -> 1

2. **Process Frequencies using Heap (size limit `k = 2`)**:
   - Element `1` (freq = 3): `pq.size() < 2`, push `{3, 1}`.
     - `pq = [{3, 1}]`
   - Element `2` (freq = 2): `pq.size() < 2`, push `{2, 2}`.
     - `pq = [{2, 2}, {3, 1}]` (top is `{2, 2}` because `2 < 3`).
   - Element `3` (freq = 1): `pq.size()` is `2`.
     - Is `freq < pq.top().first` (`1 < 2`)? Yes. Ignore.
     - `pq = [{2, 2}, {3, 1}]`

3. **Construct Result**:
   - Pop `{2, 2}` -> add `2` to `res`.
   - Pop `{3, 1}` -> add `1` to `res`.
   - `res = [2, 1]` (which contains the top 2 most frequent elements).

---

## 💻 C++ Working Code

```cpp
class Solution {
public:
    struct cmp {
        bool operator()(pair<int,int>& a, pair<int,int>& b) {
            if (a.first != b.first)
                return a.first > b.first;  // smaller freq = higher priority

            return a.second > b.second;    // tie-breaker
        }
    };
    vector<int> topKFrequent(vector<int>& a, int k) {
        int n = a.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;

        unordered_map<int,int> f;
        for (int i = 0; i < n; i++)
            f[a[i]]++;

        for (auto i : f) {
            int element = i.first;
            int freq = i.second;

            pair<int,int> curr = {freq, element};

            if (pq.size() < k) {
                pq.push(curr);
                continue;
            }

            if (curr.first < pq.top().first)
                continue;

            pq.pop();
            pq.push(curr);
        }

        vector<int> res;
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
```

---

## 📊 Complexity Analysis

- **Time Complexity**: `O(N log k)` — Building the frequency map takes `O(N)`. Pushing/popping from a heap of size `k` for `U` unique elements takes `O(U log k)` where `U <= N`.
- **Space Complexity**: `O(N)` — The hashmap stores `U` elements (at most `N`), and the heap stores `k` elements.
