# Meeting Rooms II (LeetCode 253 / GFG)

![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow)
🔗 **[Problem Link](https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1)**

---

## 📝 Problem Description

Find the minimum number of meeting rooms required to accommodate all meetings.

---

## 💡 Intuition & Core Logic

Sort start times and end times independently. Move two pointers `i` and `j`. If `start[i] < end[j]`, a meeting starts before another ends: increment `rooms`, update `res`, increment `i`. Otherwise, a meeting ends: decrement `rooms`, increment `j`.

---

## 🔄 Step-by-Step Dry Run

For `start = [900, 940, 950]`, `end = [910, 1200, 1120] -> sorted end: [910, 1120, 1200]`.
- i=0, j=0: start[0]=900 < end[0]=910 -> rooms=1, res=1, i=1.
- i=1, j=0: start[1]=940 >= end[0]=910 -> rooms=0, j=1.
- i=1, j=1: start[1]=940 < end[1]=1120 -> rooms=1, res=1, i=2.
- i=2, j=1: start[2]=950 < end[1]=1120 -> rooms=2, res=2, i=3.
- Return **2**.

---

## 💻 C++ Working Code

```cpp
class Solution {
  public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        // code here
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        int i=0;
        int j=0;
        int n=start.size();
        int m=end.size();
        int res=INT_MIN;
        int rooms=0;
        while(i<n && j<m){
            if(start[i]<end[j]){
                rooms++;
                res=max(res,rooms);
                i++;
            }
            else{
                rooms--;
                j++;
            }
        }
        return res;
        
    }
};
```

---

## 📊 Complexity Analysis

- **Time Complexity**: `O(N log N)` - We iterate through the elements, performing constant-time work per element.
- **Space Complexity**: `O(1)` - Auxiliary space usage details.
