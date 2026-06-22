# 3Sum (LeetCode 15)

![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow)
🔗 **[Problem Link](https://leetcode.com/problems/3sum/)**

---

## 📝 Problem Description

Given an integer array `nums`, return all the triplets `[nums[i], nums[j], nums[k]]` such that `nums[i] + nums[j] + nums[k] == 0` and all triplets are unique.

---

## 💡 Intuition & Core Logic

Sort the array. Loop through elements as the first element of the triplet. Use two pointers (`left` and `right`) on the remainder of the array to find pairs summing to `-nums[i]`. Skip duplicate elements for all three pointers to ensure uniqueness.

---

## 🔄 Step-by-Step Dry Run

For `nums = [-1, 0, 1, 2, -1, -4]` -> sorted: `[-4, -1, -1, 0, 1, 2]`.
- i=0 (-4): left=1 (-1), right=5 (2). Sum=-3 < 0 -> left++...
- i=1 (-1): left=2 (-1), right=5 (2). Sum = 0. Save `[-1, -1, 2]`. Move left and right, skip duplicate. left=3 (0), right=4 (1). Sum = 0. Save `[-1, 0, 1]`. Move left/right.
- i=2 (-1): Duplicate of `nums[1]`, skip.
- Return `[[-1, -1, 2], [-1, 0, 1]]`.

---

## 💻 C++ Working Code

```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){

            if (i>0 && nums[i]==nums[i-1])
            continue;


            int left=i+1;
            int right=n-1;
            int sum = -1 * nums[i];
            while(left<right){
                int s = nums[left]+nums[right];
                if(sum==s){
                    ans.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;

                    while(left<n && nums[left]==nums[left-1])
                    left++;

                    while(right>=0 && nums[right]==nums[right+1])
                    right--;
                }
                else if(s<sum){
                    left++;
                }
                else
                right--;
            }
        }
        return ans;
    }
};
```

---

## 📊 Complexity Analysis

- **Time Complexity**: `O(N^2)` - We iterate through the elements, performing constant-time work per element.
- **Space Complexity**: `O(log N) to O(N) for sorting` - Auxiliary space usage details.
