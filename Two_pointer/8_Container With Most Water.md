# Container With Most Water (LeetCode 11)

![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow)
🔗 **[Problem Link](https://leetcode.com/problems/container-with-most-water/)**

---

## 📝 Problem Description

You are given an integer array `height` of length `n`. There are `n` vertical lines drawn such that the two endpoints of the $i$-th line are `(i, 0)` and `(i, height[i])`.

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

---

## 💡 Intuition & Core Logic

1. **Two Pointer Approach (Opposite Ends)**:
   - Start with two pointers: `i = 0` (left end) and `j = n - 1` (right end).
   - The area of water formed between lines at indices `i` and `j` is:
     $$\text{Area} = \min(\text{height}[i], \text{height}[j]) \times (j - i)$$
2. **Greedy Pointer Movement**:
   - The width $(j - i)$ decreases at every step.
   - To potentially find a larger area with a smaller width, we must increase the limiting height $\min(\text{height}[i], \text{height}[j])$.
   - Therefore, move the pointer pointing to the **shorter line**:
     - If $\text{height}[i] < \text{height}[j]$, increment `i++`.
     - Otherwise, decrement `j--`.
3. **Track Maximum Area**:
   - Maintain `maxi = max(area, maxi)` across all steps until `i >= j`.

---

## 🔄 Step-by-Step Dry Run

Consider `height = [1, 8, 6, 2, 5, 4, 8, 3, 7]`

- **Initial State**: `i = 0`, `j = 8`, `maxi = 0`
- **Step 1**:
  - `len = min(1, 7) = 1`, `brea = 8 - 0 = 8`
  - `area = 1 * 8 = 8` $\rightarrow$ `maxi = max(0, 8) = 8`
  - `height[0] (1) < height[8] (7)` $\rightarrow$ `i++` (`i = 1`)
- **Step 2**:
  - `len = min(8, 7) = 7`, `brea = 8 - 1 = 7`
  - `area = 7 * 7 = 49` $\rightarrow$ `maxi = max(8, 49) = 49`
  - `height[1] (8) >= height[8] (7)` $\rightarrow$ `j--` (`j = 7`)
- ... (continues until `i == j`)
- **Final Result**: `49`

---

## 💻 C++ Working Code

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int n=height.size();
        int j=n-1;
        int maxi=0;
        while(i<j){
            int len = min(height[i],height[j]);
            int brea = j-i;
            int area=len*brea;
            maxi=max(area,maxi);

            if(height[i]<height[j])
            i++;
            else
            j--;
        }
        return maxi;
    }
};
```

---

## 📊 Complexity Analysis

- **Time Complexity**: $\mathcal{O}(N)$ — Single pass using two pointers scanning inward from opposite ends.
- **Space Complexity**: $\mathcal{O}(1)$ — Constant auxiliary space used for pointer indices and max area tracking.
