# Squares of a Sorted Array (LeetCode 977)

![Easy](https://img.shields.io/badge/Difficulty-Easy-green)
🔗 **[Problem Link](https://leetcode.com/problems/squares-of-a-sorted-array/)**

---

## 📝 Problem Description

Given an integer array `nums` sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

---

## 💡 Intuition & Core Logic

The solution separates negative and positive numbers into two arrays, squares them, reverses the negative squares (since squaring reverses order of negative numbers), and merges them using the merge step of Merge Sort.

---

## 🔄 Step-by-Step Dry Run

For `nums = [-4, -1, 0, 3, 10]`.
- Split: neg = `[-4, -1]`, pos = `[0, 3, 10]`.
- Square: neg = `[16, 1]`, pos = `[0, 9, 100]`.
- Reverse neg: neg = `[1, 16]`.
- Merge `[1, 16]` and `[0, 9, 100]`:
  - Compare 1 and 0 -> Push 0. pos index++.
  - Compare 1 and 9 -> Push 1. neg index++.
  - Compare 16 and 9 -> Push 9. pos index++.
  - Compare 16 and 100 -> Push 16. neg index++.
  - Push remaining 100.
- Result = `[0, 1, 9, 16, 100]`.

---

## 💻 C++ Working Code

```cpp
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int k=nums.size();
        vector<int>pos;
        vector<int>neg;

        for(int i=0;i<k;i++){
            if(nums[i]<0){
                neg.push_back(nums[i]);
            }
            else
            pos.push_back(nums[i]);
        }

        for(int i=0;i<pos.size();i++){
            pos[i]=pos[i]*pos[i];
        }
        for(int i=0;i<neg.size();i++){
            neg[i]=neg[i]*neg[i];
        }

        reverse(neg.begin(),neg.end());

        vector<int> ans;
        
        int i=0;
        int j=0;
        int n=pos.size();
        int m=neg.size();

        ans.reserve(m + n);
        while(i<n && j<m){
            if(pos[i]<neg[j]){
                ans.push_back(pos[i]);
                i++;
            }
            else{
                ans.push_back(neg[j]);
                j++;
            }
        }
        while(i<n){
            ans.push_back(pos[i]);
            i++;
        }
        while(j<m){
            ans.push_back(neg[j]);
            j++;
        }
        return ans;
    }
};
```

---

## 📊 Complexity Analysis

- **Time Complexity**: `O(N)` - We iterate through the elements, performing constant-time work per element.
- **Space Complexity**: `O(N) auxiliary space` - Auxiliary space usage details.
