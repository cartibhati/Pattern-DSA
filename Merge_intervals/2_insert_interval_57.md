# Insert Interval (LeetCode 57)

![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow)
🔗 **[Problem Link](https://leetcode.com/problems/insert-interval/)**

---

## 📝 Problem Description

Insert a new interval into a sorted list of non-overlapping intervals, merging if necessary.

---

## 💡 Intuition & Core Logic

Iterate through intervals: 1. Add all intervals ending before the new interval starts. 2. Merge all overlapping intervals with the new interval. 3. Add the merged new interval. 4. Add all remaining intervals.

---

## 🔄 Step-by-Step Dry Run

For `intervals = [[1,3],[6,9]]`, `newInterval = [2,5]`.
- i=0 `[1, 3]`: ends at 3 >= 2. Overlap! newInterval = `[min(1,2), max(3,5)] = [1, 5]`.
- i=1 `[6, 9]`: starts at 6 > 5. No overlap.
- Push newInterval `[1, 5]` and then `[6, 9]`.
- Result = `[[1, 5], [6, 9]]`.

---

## 💻 C++ Working Code

```cpp
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        if (a.empty()) return {};

        sort(a.begin(), a.end());

        vector<vector<int>> res;

        int st1 = a[0][0];
        int end1 = a[0][1];

        for (int i = 1; i < a.size(); i++) {
            int st2 = a[i][0];
            int end2 = a[i][1];

            if (end1 >= st2) {
                end1 = max(end1, end2);
            } else {
                res.push_back({st1, end1});
                st1 = st2;
                end1 = end2;
            }
        }

        res.push_back({st1, end1});
        return res;
    }

    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {

        intervals.push_back(newInterval);

        return merge(intervals);
    }
};
```

---

## 📊 Complexity Analysis

- **Time Complexity**: `O(N)` - We iterate through the elements, performing constant-time work per element.
- **Space Complexity**: `O(N)` - Auxiliary space usage details.
