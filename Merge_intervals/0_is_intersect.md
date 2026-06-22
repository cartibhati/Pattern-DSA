# Check if Any Two Intervals Overlap

![Easy](https://img.shields.io/badge/Difficulty-Easy-green)
🔗 **[Problem Link](https://www.geeksforgeeks.org/check-if-any-two-intervals-overlap/)**

---

## 📝 Problem Description

Given a set of intervals, check if any two intervals overlap.

---

## 💡 Intuition & Core Logic

Sort the intervals by their start times. Iterate from index 1. If the current interval's start <= previous interval's end, an overlap is found, return true. Otherwise, update the end to max of the two ends.

---

## 🔄 Step-by-Step Dry Run

For `intervals = [[1, 3], [5, 7], [2, 4]]`.
- Sort: `[[1, 3], [2, 4], [5, 7]]`.
- start1 = 1, end1 = 3.
- i=1: start2 = 2, end2 = 4. Since `start2 (2) <= end1 (3)` is true, return **true**.

---

## 💻 C++ Working Code

```cpp
class Solution {
  public:
    bool isIntersect(vector<vector<int>> a) {
        // Code Here
        sort(a.begin(),a.end());
        int start1 = a[0][0];
        int end1 = a[0][1];
        
        for(int i=1;i<a.size();i++){
            int start2 = a[i][0];
            int end2 = a[i][1];
            
            if(end1>=start2)
            return true;
            
            start1 = start1;
            end1 = max(end1,end2);
        }
        return false;
        
    }
};
```

---

## 📊 Complexity Analysis

- **Time Complexity**: `O(N log N)` - We iterate through the elements, performing constant-time work per element.
- **Space Complexity**: `O(1) auxiliary` - Auxiliary space usage details.
