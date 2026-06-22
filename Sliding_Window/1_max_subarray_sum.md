# Max Sum Subarray of size K

![Easy](https://img.shields.io/badge/Difficulty-Easy-green)
🔗 **[Problem Link](https://www.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1)**

---

## 📝 Problem Description

Given an array of integers and a number K, find the maximum sum of a contiguous subarray of size K.

---

## 💡 Intuition & Core Logic

Maintain a running sum of a window of size K. Slide the window: add the new element at the right, subtract the old element from the left. Track the maximum sum.

---

## 🔄 Step-by-Step Dry Run

For `arr = [100, 200, 300, 400]`, `K = 2`.
- Initial sum (first 2 elements) = 100 + 200 = 300. `max_sum = 300`.
- i=2: Add 300, subtract 100. `sum = 300 + 300 - 100 = 500`. `max_sum = 500`.
- i=3: Add 400, subtract 200. `sum = 500 + 400 - 200 = 700`. `max_sum = 700`.
- Return **700**.

---

## 💻 C++ Working Code

```cpp
class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int low=0;
        int high=k-1;
        int n=arr.size();
        int sum=0;
        for(int i=0;i<=high;i++){
            sum=sum+arr[i];
        }
        int ans=sum;
       while (high < n - 1) {
            low++;
            high++;

            sum = sum - arr[low - 1];
            sum = sum + arr[high];

            ans = max(ans, sum);
        }
        return ans;
        
    }
};
```

---

## 📊 Complexity Analysis

- **Time Complexity**: `O(N)` - We iterate through the elements, performing constant-time work per element.
- **Space Complexity**: `O(1)` - Auxiliary space usage details.
