# Segregate 0s and 1s

![Easy](https://img.shields.io/badge/Difficulty-Easy-green)
🔗 **[Problem Link](https://www.geeksforgeeks.org/problems/segregate-0s-and-1s5125/1)**

---

## 📝 Problem Description

Given an array of 0s and 1s in random order. Segregate 0s on left side and 1s on right side.

---

## 💡 Intuition & Core Logic

Use two pointers, `left` starting at 0, `right` starting at `n-1`. Increment `left` as long as it points to 0. Decrement `right` as long as it points to 1. If `left < right`, swap them, then move both inward.

---

## 🔄 Step-by-Step Dry Run

For `arr = [0, 1, 0, 1, 0, 0]`.
- left=0, right=5.
- `arr[left] == 0` -> left++ (now 1).
- `arr[right] == 0` -> stops.
- Swap arr[1] and arr[5]. Array becomes `[0, 0, 0, 1, 0, 1]`. left=2, right=4.
- `arr[left] == 0` -> left++ (now 3).
- `arr[right] == 0` -> stops.
- Swap arr[3] and arr[4]. Array becomes `[0, 0, 0, 0, 1, 1]`. left=4, right=3.
- `left >= right` -> stop.

Result = `[0, 0, 0, 0, 1, 1]`.

---

## 💻 C++ Working Code

```cpp
class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        // code here
        int n = arr.size();
        int i=0;
        int j=n-1;
        while(i<j){
            if(arr[i]==1 && arr[j]==0){
                swap(arr[i],arr[j]);
                i++;
                j--;
            }
            else if(arr[i]==0 && arr[j]==0)
            i++;
            else 
            j--;
            
        }
    }
};
```

---

## 📊 Complexity Analysis

- **Time Complexity**: `O(N)` - We iterate through the elements, performing constant-time work per element.
- **Space Complexity**: `O(1)` - Auxiliary space usage details.
