# 3Sum Smaller (LeetCode 259 / GFG)

![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow)
🔗 **[Problem Link](https://www.geeksforgeeks.org/problems/3-sum-smaller5017/1)**

---

## 📝 Problem Description

Given an array of distinct integers and a target sum, find the number of triplets `(i, j, k)` with sum smaller than target.

---

## 💡 Intuition & Core Logic

Sort the array. Loop through each element `nums[i]`. Set `left = i + 1` and `right = n - 1`. If `nums[i] + nums[left] + nums[right] < target`, then because the array is sorted, any element from index `left` to `right` can pair with `left` and `i` to form a sum < target. Add `right - left` to count and increment `left`. Otherwise, decrement `right`.

---

## 🔄 Step-by-Step Dry Run

For `arr = [-2, 0, 1, 3]`, `sum = 2`.
- i=0 (-2): left=1 (0), right=3 (3). sum_3 = 1 < 2. Count += (3 - 1) = 2. left++ (now 2).
- left=2 (1), right=3 (3). sum_3 = 2. Not < 2 -> right--. Stop.
- i=1 (0): left=2 (1), right=3 (3). sum_3 = 4. Not < 2 -> right--. Stop.
- Return count = **2**.

---

## 💻 C++ Working Code

```cpp
class Solution {
  public:
    int countTriplets(int target, vector<int>& arr) {
        // code here
        int n=arr.size();
        int ans=0;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n-2;i++){
            int left=i+1;
            int right=n-1;

            while(left<right){
                int sum=arr[i]+arr[left]+arr[right];
                if(sum>=target)
                right--;
                else{
                    ans=ans+(right-left);
                    left++;
                }
            }
        }
        return ans;
    }
};
```

---

## 📊 Complexity Analysis

- **Time Complexity**: `O(N^2)` - We iterate through the elements, performing constant-time work per element.
- **Space Complexity**: `O(1)` - Auxiliary space usage details.
