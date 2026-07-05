# K Closest Points to Origin (LeetCode 973)

![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow)
🔗 **[Problem Link](https://leetcode.com/problems/k-closest-points-to-origin/)**

---

## 📝 Problem Description

Given an array of `points` where `points[i] = [xi, yi]` represents a point on the **X-Y** plane and an integer `k`, return the `k` closest points to the origin `(0, 0)`.

The distance between two points on the **X-Y** plane is the Euclidean distance ($\sqrt{(x_1 - x_2)^2 + (y_1 - y_2)^2}$).

You may return the answer in **any order**. The answer is guaranteed to be unique (except for the order that it is in).

---

## 💡 Intuition & Core Logic

To find the `k` closest points, we can maintain a **Max-Heap** of size `k`. 

1. **Euclidean Distance**:
   - The distance squared is $x^2 + y^2$. We can compare the squared distances to avoid floating-point operations.
2. **Maintain a Max-Heap of size k**:
   - The heap stores `pair<int, int>` representing `{squared_distance, point_index}`.
   - Using a standard Max-Heap structure (`a.first < b.first` comparison), the point with the largest distance (farthest from origin) will sit at the top of the heap.
   - For each point:
     - Push `{distance, index}` onto the heap.
     - If the size of the heap exceeds `k`, pop the top element (which is the farthest point). This ensures we discard points that are too far away and keep only the closest ones.
3. **Result**:
   - After iterating through all points, the heap will contain exactly the `k` closest points. Pop them and retrieve the actual coordinate arrays using the stored indices.

---

## 🔄 Step-by-Step Dry Run

For `points = [[1, 3], [-2, 2]]`, `k = 1`.

1. **Calculate squared distances**:
   - `points[0] = [1, 3]`, $dist = 1^2 + 3^2 = 10$.
   - `points[1] = [-2, 2]`, $dist = (-2)^2 + 2^2 = 8$.

2. **Process using Max-Heap (size limit `k = 1`)**:
   - `i = 0`: Push `{10, 0}` -> `pq = [{10, 0}]`.
     - Size is 1 (not > 1).
   - `i = 1`: Push `{8, 1}` -> `pq = [{10, 0}, {8, 1}]` (top is `{10, 0}`).
     - Size is 2 (> 1). Pop the top element `{10, 0}`.
     - `pq = [{8, 1}]`.

3. **Construct Result**:
   - Pop `{8, 1}` -> retrieve `points[1] = [-2, 2]`.
   - `ans = [[-2, 2]]`.

---

## 💻 C++ Working Code

```cpp
class Solution {
public:
    struct cmp {
        bool operator()(const pair<int,int>& a, const pair<int,int>& b) const {
            return a.first < b.first;   // larger distance has higher priority
        }
    };

    int dist(vector<int>& point) {
        return point[0] * point[0] + point[1] * point[1];
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;

        for (int i = 0; i < points.size(); i++) {
            pq.push({dist(points[i]), i});

            if (pq.size() > k)
                pq.pop();
        }

        vector<vector<int>> ans;
        while (!pq.empty()) {
            ans.push_back(points[pq.top().second]); // second is the index
            pq.pop();
        }

        return ans;
    }
};
```

---

## 📊 Complexity Analysis

- **Time Complexity**: `O(N log k)` — Calculating distance for `N` points takes `O(N)`. Storing them in a heap of size `k` takes `O(log k)` for each push/pop, leading to an overall time complexity of `O(N log k)`.
- **Space Complexity**: `O(k)` — The Max-Heap stores at most `k` elements at any time.
