# Interval List Intersections (LeetCode 986)

![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow)
🔗 **[Problem Link](https://leetcode.com/problems/interval-list-intersections/)**

---

## 📝 Problem Description

Find the intersection of two sorted, disjoint closed interval lists.

---

## 💡 Intuition & Core Logic

Use two pointers `i` and `j`. Find intersection start `max(A[i][0], B[j][0])` and end `min(A[i][1], B[j][1])`. If `start <= end`, save it. Increment the pointer of the interval list that ends first.

---

## 🔄 Step-by-Step Dry Run

For `A = [[0,2],[5,10]], B = [[1,5],[8,12]]`.
- i=0, j=0: intersection = `[max(0,1), min(2,5)] = [1, 2]`. Push `[1, 2]`. A[0] ends first -> i++.
- i=1, j=0: intersection = `[max(5,1), min(10,5)] = [5, 5]`. Push `[5, 5]`. B[0] ends first -> j++.
- i=1, j=1: intersection = `[max(5,8), min(10,12)] = [8, 10]`. Push `[8, 10]`. A[1] ends first -> i++.
- Result: `[[1,2],[5,5],[8,10]]`.

---

## 💻 C++ Working Code

```cpp
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& a, vector<vector<int>>& b) {
        int n=a.size();
        int m=b.size();
        vector<vector<int>>res;
        int i=0;
        int j=0;
        while(i<n && j<m){
            int start1 = a[i][0];
            int end1 = a[i][1];
            int start2 = b[j][0];
            int end2 = b[j][1];

            if(start1<=start2){
                if(end1>=start2){
                    int s = max(start1, start2);
                    int e = min(end1,end2);
                    res.push_back({s,e});
                }
            }
            else{
                if(end2>=start1){
                    int s = max(start1, start2);
                    int e = min(end1,end2);
                    res.push_back({s,e});
                }
            }
            if(end1<=end2)
            i++;
            else
            j++;
        }
        return res;
    }
};
```

---

## 📊 Complexity Analysis

- **Time Complexity**: `O(N + M)` - We iterate through the elements, performing constant-time work per element.
- **Space Complexity**: `O(1) auxiliary` - Auxiliary space usage details.
